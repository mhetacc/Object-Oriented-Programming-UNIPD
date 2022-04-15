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
public class Laptop extends Tower {
    private Screen screen;
    private int battery; //mAh
    private int weight; //in grammi
    private double pscore (){
       /* System.out.println("Latop::1="+battery);
        System.out.println("Latop::2="+(int)getPrice());
        System.out.println("Laptop::3 ="+screen.getScore());
        System.out.println("Laptop::4 ="+partialScore());
        System.out.println("Laptop::5 ="+(screen.getScore()*battery));
        System.out.println("Laptop::6 ="+(partialScore() + (screen.getScore()*battery)));
        System.out.println("Laptop::SCORE ="+((partialScore() + (screen.getScore()*battery))/getPrice()));
      */return ((partialScore() + (screen.getScore()*battery))/(int)getPrice());  
}

    public double Score(){   //override
        return pscore();
}
    public double getScoreaux() {
    	return pscore();
    }

    public void Print(){   //override
    super.Print();
    screen.Print();
    System.out.println("Batteria= "+battery+" mAh");
    System.out.println("Peso= "+weight);
}

    public void setBattery (int b){
        if(b>0)
            battery=b;
        else System.err.println(" set Error, inserire valore>0 ");
}
    public void setResolution (int w, int h){
        if(w>=0 && h>=0)
            screen.setRes(w, h);
        else System.err.println(" set Error, inserire valore>0 ");
}
    public void setDimension (double d){
        if(d>0)
            screen.setDim(d);
        else System.err.println("set Error, inserire val >0");
}

    public void modifyBattery (int b){
        if(battery+b<0) System.err.println(" modify Error, valore inserito rende mAh batteria negativi ");
        else battery+=b;
}


    public void setWeight (int wgh){
        if(wgh>0)
            weight=wgh;
        else System.err.println(" set Error, inserire valore>0 ");
}
    public void modifyWeight (int wgh){
        if(weight+wgh<0) System.err.println(" modify Error valore inserito rende dimensione diagonale schermo negativa ");
        else weight+=wgh;
}
    
    public Laptop(int cpuclock, int gpuclock, int ramclock, 
                    double cpumem, double gpumem, double rammem, double memmem,
                    int cpucores, int gpucores,
                    boolean cpuhy, boolean gpupres, int gpuband,
                    int write, int read,
                    double prc,
                    int resW, int resH, double screendim,
                    int batt, int wgh){
        super(cpuclock, gpuclock, ramclock, cpumem, gpumem, rammem, memmem, cpucores, gpucores, cpuhy, gpupres, gpuband, write, read, prc);
        screen=new Screen(resW, resH, screendim);
        battery=batt;
        weight=wgh;
    }
    
    public Laptop () {
        screen=new Screen();
        battery=0;
        weight=0;
    }
}
