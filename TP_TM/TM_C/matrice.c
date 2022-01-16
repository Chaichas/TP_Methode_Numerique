void InvdiagMat(int NbElement, double **Mat)
{
	double ** temp;
	int i;
	temp= malloc( NbElement * sizeof(double) );
	
	for(i=0;i<NbElement;i++)
	{
		temp[i]= malloc( NbElement * sizeof(double) );
		
		for(int j=0;j<NbElement;j++)
		{
			temp[i][j]=0;
		}
	}

	for(i=0;i<NbElement;i++)
    {
	 	
	 	for(int j=0;j<NbElement;j++)
		{
		 		temp[i][i]=1/Mat[i][i];
		 		if(j!=i)
	    		{
					temp[i][j]=-Mat[i][j]/Mat[i][i];
				}
		 		for(int k=0;k<NbElement;k++)
		 		{
		 		    
					if(k!=i)
					{
		 			 		temp[k][i]=Mat[k][i]/Mat[i][i];
					}
					if(j!=i &&k!=i)
					{
					 		temp[k][j]=Mat[k][j]-Mat[i][j]*Mat[k][i]/Mat[i][i];
                    }		
				}
			 		
		}
		for(int i=0;i<NbElement;i++)
    	{
            for(int j=0;j<NbElement;j++)
            {
                Mat[i][j]=temp[i][j];
            }
        
       }
	}
}

