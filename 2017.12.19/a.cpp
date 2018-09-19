#include<stdio.h>
#include<utmp.h>
#include<fcntl.h>
#include<unistd.h>
#include<time.h>

int main(){
	struct utmp current_re;
	int utmpfd;
	int sz=sizeof(current_re);
	utmpfd=open(UTMP_FILE,O_RDONLY);
	printf("utmp: %d\n",utmpfd);
	while(read(utmpfd,&current_re,sz)){
	// show_info(&current_re);
		if(current_re.ut_type==USER_PROCESS){
			printf("%s %s %s %s %s\n",current_re.ut_line,current_re.ut_id,current_re.ut_user,current_re.ut_host,current_re.ut_name);
			// printf("%s\n",ctime(current_re.ut_tv.tv_sec));	
		}
		
		
	}
	close(utmpfd);
	return 0;
}