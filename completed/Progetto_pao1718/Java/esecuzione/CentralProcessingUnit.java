/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
//package esecuzione;

/**
 *
 * @author mhetac
 */
public class CentralProcessingUnit extends BaseComponent {
    private static int performance_percentage_increase=10;  //serve perche' con hyperthreading si ha un aumento performace di circa il 10%
    private int num_physical_cores;
    private boolean hypertrheading;
    private double Score () {
        int sum, var=0;
        double mem=getMem();
        sum= (int)((num_physical_cores*getClock())+mem);
        if (hypertrheading){
            var= (sum*performance_percentage_increase)/100; //aumento performance percentuale sistemata in modo tale che si traduca in aumento medio del 10% nelle performance del sistema finale
            sum+=var;
        }
        if(mem>4 && mem<=8)
            var=(sum*20)/100;
        else{
            if(mem<=4)
            	var=(sum*10)/100;
            if(mem>8)
            	var=(sum*30)/100;
        }
        sum+=var;
        return sum;}
    
    public double getScore(){ //override
        return Score();
    }
    public void modifyCores (int c){
        if(num_physical_cores+c<0) System.err.println(" modify Error, valore comporta numero cores negativo");
        else num_physical_cores+=c;
   }
    public void setCores (int c){
        if(c>0)
        num_physical_cores=c;
        else System.err.println(" set Error, inserire valore>0 ");
    }
    public void setHyperT (boolean hy){
        hypertrheading=hy;
        }
   
    public void Print(){  //override
    	double mem=getMem();
            if(hypertrheading){
            	System.out.println("La CPU con hypertreading ha "+num_physical_cores+" cores "+getClock()+" MHz "+mem+" MB di cache");
            	}
            else
            	System.out.println("La CPU ha "+num_physical_cores+" cores "+getClock()+" MHz "+mem+" MB di cache");
        
    }
    
    public CentralProcessingUnit (int clock, double mem, int cores, boolean hy){
        super(clock, mem); //richiama il costruttore della classe padre BaseComponent
        num_physical_cores=cores;
        hypertrheading=hy;
    }
    
    public CentralProcessingUnit(){  //costruttore senza parametri, pone tutto a zero
        //super();  implicita
        num_physical_cores=0;
        hypertrheading=false;
    }
}
