#define MAX_SET_NR 512
int handle_ret_flags_set[MAX_SET_NR] = {0};
int handle_ret_unset[MAX_SET_NR] = {0};
int *handle_set_ptr = NULL;
int *handle_unset_ptr = NULL;


void init_unset_set()
{
    int i;
    for(i = 0;i < MAX_SET_NR;i++)
    {
        handle_ret_unset[i] = i;
    }
}

int main()
{
	int i,k = 0,z = 0;
	int loop_cnt = 0;
  loop_cnt = MAX_SET_NR;
  init_unset_set();
	
	handle_set_ptr = handle_ret_flags_set;
  handle_unset_ptr = handle_ret_unset;
	sleep(2);
	
	while(1){
	 for(i = 0;i < loop_cnt;i++)
	 {
		 if(handle_set_ptr[handle_unset_ptr[i]] == 1)
		 {
			k++;    
		 }
		 else
		 {
			handle_ret_unset[z] = i;
			z++;
		 }
	 }
	 if(z > 0){
		handle_unset_ptr = handle_ret_unset;
	 }
	 loop_cnt = z;
	 z = 0;
	 if(k == logic_chip_num){
		printf("%s:%d, success \n\r",__FUNCTION__,__LINE__);
		break;
	 }
	 sleep(1);
	}

}


handle_each_flag_fun(int id)
{
	
	/*
		handle 
		handle finish
	*/
	handle_ret_flags_set[id] = 1;
}
