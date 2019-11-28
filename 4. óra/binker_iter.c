int binker(int t[], int bal, int jobb, int a){
	while(bal<=jobb){
		int kozep = (bal + jobb) / 2;
		if(t[kozep] == a){ 
			return kozep;
		}
		if(t[kozep] < a)
			bal = kozep + 1;
		if(t[kozep] > a) 
			jobb = kozep - 1;  
	}
	return -1;
}

//hivas
pos = binker(t, 0, N-1, x);
