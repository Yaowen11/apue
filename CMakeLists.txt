cmake_minimum_required(VERSION 3.15)
project(apue C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(apue
        common/apue.h
        common/apue_error.h
        common/apue_log.h
        chapterOne/myls.c
        main.c chapterOne/copy.c chapterOne/inout.c chapterOne/dumpProcessId.c chapterOne/execInStdIn.c main.c chapterOne/err.c chapterOne/dumpUserGroupID.c chapterOne/signal.c chapterOne/wrfile.c chapterTwo/sysconf.c chapterTwo/pathMax.c chapterTwo/openFile.c chapterThree/checkLseek.c "chapterThree/cavityFile.c" chapterThree/ioEffect.c chapterThree/changFdAttribute.c chapterFour/fileStat.c chapterFour/access.c chapterFour/umask.c chapterFour/changFileMode.c chapterFour/delete.c chapterFour/changTime.c chapterFour/readDir.c chapterFour/mycd.c chapterFour/pathname.c chapterFour/deviceNum.c chapterFive/stdInOut.c chapterFive/stdIO.c chapterFive/tmpfile.c chapterFive/tmpFolds.c chapterFive/memStream.c chapterSeven/hello.c chapterSeven/atexit.c chapterSeven/argc.c chapterSeven/resourceLimits.c chapterEight/fork.c chapterEight/vfork.c chapterEight/dumpProcessExitStatus.c chapterEight/twoFork.c chapterEight/caseCondition.c chapterEight/exec.c chapterEight/echoall.c chapterEight/system.c chapterEight/pr_exit.c chapterEight/tsys.c chapterEight/processAccounting.c chapterEight/processAccount.c chapterEight/renice.c chapterEight/processTimes.c chapterTen/signalUser.c chapterTen/signal2.c chapterTen/newRecome.c chapterTen/sigcld.c chapterTen/slowIOAlrm.c chapterTen/slowSyscall.c chapterTen/signalSet.c chapterTen/pr_mask.c chapterTen/sigmask.c chapterTen/sigJump.c chapterTen/sigsuspend.c chapterTen/sigsuspendChangeVariables.c chapterTen/parentChildSync.c chapterTen/sigTask.c chapterEleven/dumpPthreadId.c chapterEleven/diePthread.c chapterEleven/errCallPthsJoin.c chapterEleven/pthsClearHandler.c chapterEleven/pthsMutex.c)
