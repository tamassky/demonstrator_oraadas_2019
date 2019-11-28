int binker(int t[], int bal, int jobb, int a){
	if(bal<=jobb){
		int kozep = (bal + jobb) / 2;
		if(t[kozep] == a){ 
			return kozep;
		}
		if(t[kozep] < a)
			return binker(t, kozep+1, jobb, a);
		if(t[kozep] > a) 
			return binker(t, bal, kozep+1, a);  
	}
	return -1;
}

//hivas
pos = binker(t, 0, N-1, x);
