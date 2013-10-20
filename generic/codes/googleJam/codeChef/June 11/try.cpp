if(LY - HY > 0){
				it = lower_bound(&arrAY[HY], &arrAY[LY + 1], a);
				lc = (int)(it - &arrAY[HY]);
				if((lc - HY) < (LY - lc)){
					for(j = HY; j <= lc; ++j){
						arrAY[SIZE - j - 1] = arrAY[j];
						arrRY[SIZE - j - 1] = arrRY[j];
					}
					arrAY[lc] = a;
					arrRY[lc] = r;
				}
				else{
					for(j = lc; j <= LY; ++j){
						arrAY[SIZE - j - 1] = arrAY[j];
						arrRY[SIZE - j - 1] = arrRY[j];
					}
				}
			}
