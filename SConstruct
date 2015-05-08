import glob
import os
import re
import scons_opt
#get the mode flag from the command line
#default to 'release' if the user didn't specify

mode = ARGUMENTS.get('Release',0)
#check if the user has been naughty: only 'debug' or 'release' allowed

configMode = 'Debug' if mode == 0 else 'Release'


#tell the user what we're doing
print '**** Compiling in ' + configMode + ' mode...'

env = Environment()
print 'construting PLATFORM:',env['PLATFORM']
opt = scons_opt.GetOpt(env['PLATFORM'],configMode)


def UpdateOpt(env,opt):
	for k , v in opt.iteritems():
		env[k] = v

UpdateOpt(env,opt)


buildroot = './' + configMode   #holds the root of the build directory tree


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