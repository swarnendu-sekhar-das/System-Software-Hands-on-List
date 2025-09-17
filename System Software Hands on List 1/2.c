/*
============================================================================
Name : 2.c
Author : Swarnendu Sekhar Das
Description : Write a simple program to execute in an infinite loop at the background. Go to /proc directory and
				 identify all the process related information in the corresponding proc directory.
		
Date: 30th Aug, 2025.
============================================================================
*/

#include <unistd.h>
#include <stdio.h>

int main (){
	while(1){
		sleep(1);
	}
	return 0;
}

/*
swarnendu-sekhar-das@swarnendu-sekhar-das-G5-5500:~/Desktop/SS-Hands on List 1$ gcc 2.c -o 2
swarnendu-sekhar-das@swarnendu-sekhar-das-G5-5500:~/Desktop/SS-Hands on List 1$ ./2 &
[1] 6118

swarnendu-sekhar-das@swarnendu-sekhar-das-G5-5500:/proc/6118$ ls
arch_status  cmdline             environ  ksm_merging_pages  maps        ns             patch_state  sessionid     statm           timerslack_ns
attr         comm                exe      ksm_stat           mem         numa_maps      personality  setgroups     status          uid_map
autogroup    coredump_filter     fd       latency            mountinfo   oom_adj        projid_map   smaps         syscall         wchan
auxv         cpu_resctrl_groups  fdinfo   limits             mounts      oom_score      root         smaps_rollup  task
cgroup       cpuset              gid_map  loginuid           mountstats  oom_score_adj  sched        stack         timens_offsets
clear_refs   cwd                 io       map_files          net         pagemap        schedstat    stat          timers

*/