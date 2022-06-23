#ifndef CURSORS_BINDATA_H
#define CURSORS_BINDATA_H


#include <vector>

class BinData {
public:


	inline void PushString(const char *str){
		for(size_t i = 0; str[i] != 0; ++i){
			PushUint8(str[i]);
		}
		PushUint8(0);
	}

	inline void PushUint8(uint8_t v){ m_Data.push_back(v); };
	
	inline void PushUint16(uint16_t v){
		m_Data.reserve(m_Data.size() + 2);
		m_Data.push_back((v >> 0) & 0xFF);
		m_Data.push_back((v >> 8) & 0xFF);
	}

	inline void PushUint32(uint32_t v){
		m_Data.reserve(m_Data.size() + 4);
		m_Data.push_back((v >> 0) & 0xFF);
		m_Data.push_back((v >> 8) & 0xFF);
		m_Data.push_back((v >> 16) & 0xFF);
		m_Data.push_back((v >> 24) & 0xFF);
	}

	inline char *Data(){ return m_Data.data(); }
	inline size_t Length(){ return m_Data.size(); }

private:
	std::vector<char> m_Data;
};

#endif