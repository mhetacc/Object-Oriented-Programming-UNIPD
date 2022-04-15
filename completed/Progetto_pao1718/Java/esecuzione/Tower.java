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
public class Tower extends Computer {
    private double pscore(){
        return (partialScore()/getPrice());
}

    public double Score (){  //override
        return pscore();
}
    
    public void Print(){   //override
        super.Print();
        }
    
    public Tower(int cpuclock, int gpuclock, int ramclock, 
                    double cpumem, double gpumem, double rammem, double memmem,
                    int cpucores, int gpucores,
                    boolean cpuhy, boolean gpupres, int gpuband,
                    int write, int read,
                    double prc) {
        
        super(cpuclock, gpuclock, ramclock, cpumem, gpumem, rammem, memmem, cpucores, gpucores, cpuhy, gpupres, gpuband, write, read, prc);
    }
    
    public Tower () {}
}
