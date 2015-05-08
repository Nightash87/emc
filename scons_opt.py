# -*- coding: utf8 -*-
import os
import copy

# CPPPATH: 额外头文件目录
# CCFLAGS: 编译器参数选项
# LIBPATH: 额外库文件目录
# LIBS:需要链接的具体库名

scons_opt = \
{
	'win32':
	{
		'All':
		{
			'CPPPATH' : [os.environ['BOOST_ROOT']],
			'CCPDBFLAGS': ['${(PDB and "/Zi /Fd%s" % File(PDB)) or ""}'],
			'CCFLAGS':['-DWIN32'],
			'LIBPATH': [os.environ['BOOST_ROOT'] + '/stage/lib64'],
			'LIBS': []
		},
		'Debug':
		{
			'CCFLAGS': ['-W3', '-EHsc', '-D_DEBUG', '/MDd']
		},
		'Release':
		{
			'CCFLAGS': ['-O2', '-EHsc', '-DNDEBUG', '/MD']
		}
	},
	'cygwin':
	{
		'All':
		{
			'CPPPATH' : ['/usr/local/include'],
			'CCFLAGS': ['-Wall', '-m64', '-std=c++11','-g'],
			'LIBPATH': ['/usr/local/lib']
		},
		'Debug':
		{
			'CCFLAGS': ['-O0','-D_DEBUG']
		},
		'Release':
		{
			'CCFLAGS': ['-O3', '-DNDEBUG']
		}
	}
}

def GetOpt(platform,configMode):
	d_all = scons_opt.get(platform).get('All',{})
	d_mode = scons_opt.get(platform).get(configMode,{})
	ret = copy.deepcopy(d_all)
	for k , v in d_mode.iteritems():
		value = ret.get(k,[])
		if value == None:
			ret[k] = v
		else:
			value += v
	return ret

def Main():
	print GetOpt('cygwin',False)

if __name__ == '__main__' : Main()
