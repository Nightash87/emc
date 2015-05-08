import glob
import os
import re

#get the mode flag from the command line
#default to 'release' if the user didn't specify

print ARGUMENTS
mode = ARGUMENTS.get('Release',0)
#check if the user has been naughty: only 'debug' or 'release' allowed

mymode = 'Debug' if mode == 0 else 'Release'


#tell the user what we're doing
print '**** Compiling in ' + mymode + ' mode...'

opt = {}
env = Environment()
if env['PLATFORM'] == 'win32':
	opt['CPPPATH'] = os.environ['BOOST_ROOT']
	opt['CCPDBFLAGS'] = ['${(PDB and "/Zi /Fd%s" % File(PDB)) or ""}']
	opt['CCFLAGS'] = ['-DWIN32']

	if mymode == 'Debug':
		opt['CCFLAGS'] += ['-W3', '-EHsc', '-D_DEBUG', '/MDd']
	else:
		opt['CCFLAGS'] += ['-O2', '-EHsc', '-DNDEBUG', '/MD']
else:
	opt['CPPPATH'] = '/usr/local/include'
	opt['CCFLAGS'] = ['-Wall', '-m64', '-std=c++11']

def UpdateOpt(env,opt):
	for k , v in opt.iteritems():
		env[k] = v


UpdateOpt(env,opt)


buildroot = './' + mymode   #holds the root of the build directory tree


#-------
#From here on will be common to all projects

builddir = buildroot + '/'   						#holds the build directory for this project

#specify the build directory
VariantDir('#' + builddir, "#.", duplicate=0)


def isExcutableProject(dirName):
	return os.path.isdir(dirName) and re.search('^item\d\d?' ,dirName)

def CompileProject(project,build_dir,build_env):
	print 'CompileProject %s' % i
	targetpath = build_dir + '/' + project   			#holds the path to the executable in the build directory
	build_env.Program(targetpath, source=map(lambda x: '#' + build_dir + '/' + x, glob.glob('./'+project+'/'+'*.cpp')))


ProjectList =  [ CompileProject(i,builddir,env)  for i in os.listdir(os.getcwd()) if isExcutableProject(i) ]