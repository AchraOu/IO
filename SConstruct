
env = Environment()

env.Append(
	LIBS = 'uv',
	CCFLAGS = [
		'-pthread',
		'-g',
		'-Ofast',
		'-fno-omit-frame-pointer',
		'-flto',
		'-march=native',
		'--std=c++11',
	],
	
	LINKFLAGS = [
		'-pthread',
	],
	
	CPPPATH = [ 'server/src' ],
)

env.Program(
	target = 'bin/server',
	source = [
		Glob("server/src/*.cpp")
	],
)
