#ifndef CURSORS_LEVEL_H
#define CURSORS_LEVEL_H

#include "BinData.h"
#include "Line.h"
#include "Point.h"

#define LEVEL_WIDTH 400
#define LEVEL_HEIGHT 300

class Cursor;

struct LevelObject;

class LevelManager;
class Level {
public:
	Level(int initialX, int initialY);
	virtual ~Level(){};
	
	void Init(){ OnInit(); ForceThink(); }
	virtual void OnInit(){}

	int Width(){ return LEVEL_WIDTH; }
	int Height(){ return LEVEL_HEIGHT; }

	inline bool IsSolid(int x, int y);
	inline bool IsSolid(const Point &p){ return IsSolid(p.x, p.y); };
	inline void IncSolid(int x, int y){ ++m_SolidMap[x][y]; }
	inline void DecSolid(int x, int y){ --m_SolidMap[x][y]; }
	inline bool HasCursor(Cursor *cursor);
	Point GetUnstuckPosition(Point pos);
	void PaintAreas();
	void CreateUpdate();
	void Think();
	void ForceThink();
	void AddCursor(Cursor *cursor);
	void RemoveCursor(Cursor *cursor);
	void TeleportCursor(Cursor *cursor, Level *newLevel);
	LevelObject *AddObject(LevelObject *obj);
	void RemoveObject(LevelObject *obj);
	inline void InvalidateAreas(){ m_bNeedsRepaint = true; }
	inline const std::vector<Cursor*>& GetCursors(){ return m_Cursors; }
	bool HasObject(LevelObject *obj);
	inline void SetSoloLevel(bool v){ m_bSoloLevel = v; }

	void ResetEveryone();

	void TryMoveCursor(Cursor *c, uint16_t x, uint16_t y);
	void TryClick(Cursor *c, uint16_t x, uint16_t y);
	void TryDrawLine(Cursor *c, uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2);

	inline uint64_t GetTime(){ return m_iTime; }

	void CreatePredictionError(Cursor *c);


	// Functions run in single-threaded phase:
	void STSolveTeleports();
	void STSendUpdate();
	void STKickAFK();
	

	virtual void OnThink(){};

private:
	inline bool IsPainted(int x, int y){ return m_Areas[x][y] != 0; }
	inline bool PathExists(const Point &p1, const Point &p2){ return !IsSolid(p2) && m_Areas[p1.x][p1.y] == m_Areas[p2.x][p2.y]; }
	Point TraceLine(int x1, int y1, int x2, int y2);
	void SendFullLevel(Cursor *cursor);
	void EncodeCursors(BinData &out);
	void UnstuckCursors();

	bool m_bNeedsRepaint;
	bool m_bSoloLevel;
	int m_iInitialX;
	int m_iInitialY;
	uint64_t m_iTime;
	uint64_t m_iLastSuccess;

	uint32_t m_iCurObjectID;
	std::vector<uint32_t> m_AvailableObjectIDs;

	struct ScheduledTeleport {
		Cursor *cursor;
		Level *newLevel;
	};

	char *m_pUpdatePacket;
	std::vector<Cursor*> m_Cursors;
	std::vector<LevelObject*> m_Objects;
	std::vector<ScheduledTeleport> m_ScheduledTeleports;

	// Stuff sent in SendUpdates
	std::vector<Point> m_PendingClicks;
	std::vector<LevelObject*> m_AddedObjects;
	std::vector<LevelObject*> m_RemovedObjects;
	std::vector<Line> m_PendingLines;
	/////////////////////////////

	uint8_t m_SolidMap[LEVEL_WIDTH][LEVEL_HEIGHT];
	uint m_Areas[LEVEL_WIDTH][LEVEL_HEIGHT];

	friend LevelManager;
};

bool Level::IsSolid(int x, int y){
	if(x < 0 || y < 0 || x >= Width() || y >= Height()) return true;
	return m_SolidMap[x][y] > 0;
}

bool Level::HasCursor(Cursor *cursor){
	for(Cursor *c : m_Cursors){
		if(c == cursor) return true;
	}
	return false;
}

#endif