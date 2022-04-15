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
public class GraphicProcessingUnit extends BaseComponent {
    private int num_physical_cores;
    private int bandwith; //GB/s
    private boolean gpuPresence;
    private double Score (){
        return (getClock() * (num_physical_cores/100) + bandwith + getMem());
        }
    
    public double getScore(){ //override
        return Score();
        }
    public void modifyCores (int c){
        if(num_physical_cores+c<0) System.err.println(" modify Error, valore inserito rende numero cores negativo ");
        else num_physical_cores+=c;
   }
    public void modifyBand (int b){
        if(num_physical_cores+b<0) System.err.println(" modify Error, valore inserito rende quantita' banda negativa ");
        else bandwith+=b;
    }
    public void setCores (int c){
        if(c>0)
        num_physical_cores=c;
        else System.err.println(" set Error, inserire valore>0 ");
    }
    public void setBand (int b){
        if(b>0)
        bandwith=b;
        else System.err.println(" set Error, inserire valore>0 ");
    }
    public boolean thereIsGPU () {return gpuPresence;}   // e' possibile che alcune macchine siano costruite senza GPU dedicata
    public void presenceGPU (boolean b){
        gpuPresence=b;
    }
    
    public void Print() {  //override
        double clock=getClock();
        if(clock>=1000) { //se clock>= 1GHz
        clock=clock/1000.0;
        System.out.println("La GPU ha "+num_physical_cores + " cores " + clock + " GHz "+getMem() + " MB di DRAM " +bandwith + " MB/s");
        }
        else
        	System.out.println("La GPU ha "+num_physical_cores + " cores " + clock + " MHz "+getMem() + " MB di DRAM " +bandwith + " MB/s");

    }
    
    public GraphicProcessingUnit (int clock, double mem, int cores, int band, boolean presence){
        super(clock, mem);
        num_physical_cores=cores;
        bandwith=band;
        gpuPresence=presence;
    }
    
    public GraphicProcessingUnit (){
        num_physical_cores=0;
        bandwith=0;
        gpuPresence=false;
    }
}
