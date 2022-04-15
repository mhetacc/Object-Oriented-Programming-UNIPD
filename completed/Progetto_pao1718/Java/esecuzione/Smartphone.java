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
public class Smartphone extends Laptop {
    private int broadband_gen;  //generazione banda es: 3G, 4G, ...
    private double pscore(){
        return getScoreaux()*broadband_gen;
        }

    
    public void Print () {  //override
    	super.Print();
    	System.out.println("La generazione e' "+broadband_gen+" G");
    }
    public double Score() {return pscore();}   //override
    public void setGen (int gen){
        if(gen>0)
            broadband_gen=gen;
        else System.err.println(" set Error, inserire valore>0 ");
    }
    
    public Smartphone(int cpuclock, int gpuclock, int ramclock, 
                    double cpumem, double gpumem, double rammem, double memmem,
                    int cpucores, int gpucores,
                    boolean cpuhy, boolean gpupres, int gpuband,
                    int write, int read,
                    double prc,
                    int resW, int resH, double screendim,
                    int batt, int wgh,
                    int broadb){
        super(cpuclock, gpuclock, ramclock, cpumem, gpumem, rammem, memmem, cpucores, gpucores, cpuhy, gpupres, gpuband, write, read, prc,resW, resH, screendim, batt, wgh);
        broadband_gen=broadb;
    }
    
    public Smartphone () {
        broadband_gen=1;
    }
}
