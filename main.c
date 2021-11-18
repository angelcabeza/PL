main{
begin_local_var
	int ve ;
	float vf ;
	char vc ;
	bool vl ;
	list of int pe, pe2 ;
	list of float pf, pf2 ;
	list of char pc, pc2 ;
	list of bool pl ;
end_local_var

int funcionA (int a1, float a2, char a3){
	begin_local_var
		int x1, x2 ;
	end_local_var
	char funcionB (char b1, bool b2){
		begin_local_var
			float xf, x2 ;
		end_local_var
		float funcionC (bool c1, int c2){
			begin_local_var
				float x1 ;
			end_local_var
			x1= 1.3 ;
			if (c2>10){
				c2= c2-1 ;
			}
			else{
				x1= 3.1 ;
			}
			return x1 ;
		}
		xf= functionC (true, 10);
		x2= xf*(funcionC(false,1)-funcionC(true,23))/10.0;
		while (x2*funcionC(false,1)-xf<10.0){
			x2= x2*xf ;
		}
	}
	float funcionD (float d1){
		begin_local_var
			char dato ;
			int valor ;
		end_local_var
		char funcionE (char e1, char e2)
		{
			
		}
		read "introduzca un valor entero: ", valor ;
		if (d1>0.0){
			begin_local_var
				int dato ;
			end_local_var
			dato= 2 ;
			dato= valor*20/dato ;
		}
		else {
			valor= valor * 100 ;
			d1= d1/1000.0 ;
		}
		return d1 ;
	}
	}
}