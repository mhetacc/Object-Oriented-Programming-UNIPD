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
public abstract class Computer {
    private CentralProcessingUnit cpu;
    private GraphicProcessingUnit gpu;
    private RandomAccessMemory ram;
    private SecondaryMemory mem;
    private double price;
    private double pscore (){
        if (gpu.thereIsGPU()){
        return (cpu.getScore() + gpu.getScore() + ram.getScore() + mem.getScore());}
        else
            return (cpu.getScore() + ram.getScore() + mem.getScore());
    }

  /*  public CentralProcessingUnit getCPU () {return cpu;}
    public GraphicProcessingUnit getGPU () {return gpu;}
    public RandomAccessMemory getRAM () {return ram;}
    public SecondaryMemory getMEM () {return mem;}
    */
    
    public Computer(int cpuclock, int gpuclock, int ramclock, 
                    double cpumem, double gpumem, double rammem, double memmem,
                    int cpucores, int gpucores,
                    boolean cpuhy, boolean gpupres, int gpuband,
                    int write, int read,
                    double prc) {
        
        cpu=new CentralProcessingUnit(cpuclock, cpumem, cpucores, cpuhy);
        gpu=new GraphicProcessingUnit(gpuclock, gpumem, gpucores, gpuband, gpupres);
        ram=new RandomAccessMemory(ramclock, rammem);
        mem=new SecondaryMemory(0, memmem, write, read);
        price=prc;
    }
    
    public Computer () {
        cpu=new CentralProcessingUnit();
        gpu=new GraphicProcessingUnit();
        ram=new RandomAccessMemory();
        mem=new SecondaryMemory();
        price=0;
    }
    
    public double partialScore (){
        return pscore();
        }
    public double getPrice (){return price;}

    public void Print(){
        if(gpu.thereIsGPU()){
            cpu.Print();
            gpu.Print();
            ram.Print();
            mem.Print();
            System.out.println("Il prezzo e' "+price);
        }
        else {
            cpu.Print();
            ram.Print();
            mem.Print();
            System.out.println("Il prezzo e' "+price);
        }
        }

    public void modifyMemCPU (double m){
        cpu.modifyMemory(m);
        }
    public void modifyMemGPU (double m){
        gpu.modifyMemory(m);
        }
    public void modifyMemRAM (double m){
        ram.modifyMemory(m);
        }
    public void modifyMemMEM (double m){
        mem.modifyMemory(m);
        }
    public void setMemCPU (double m){
        cpu.setMemory(m);
        }
    public void setMemGPU (double m){
        gpu.setMemory(m);
        }
    public void setMemRAM (double m){
        ram.setMemory(m);
        }
    public void setMemMEM (double m){
        mem.setMemory(m);
        }

    public void modifyClockCPU (int c){
        cpu.modifyClock(c);
        }
    public void modifyClockGPU (int c){
        gpu.modifyClock(c);
        }
    public void modifyClockRAM (int c){
        ram.modifyClock(c);
        }
    public void setClockCPU (int c){
        cpu.setClock(c);
        }
    public void setClockGPU (int c){
        gpu.setClock(c);
        }
    public void setClockRAM (int c){
        ram.setClock(c);
        }

    public void modifyCoresCPU (int c){
        cpu.modifyCores(c);
        }
    public void modifyCoresGPU (int c){
        gpu.modifyCores(c);
        }
    public void setCoresCPU (int c){
        cpu.setCores(c);
        }
    public void setCoresGPU (int c){
        gpu.setCores(c);
        }

    public void setHyperCPU (boolean hy){
        cpu.setHyperT(hy);
        }

    public void modifyBandGPU (int b){
        gpu.modifyBand(b);
        }
    public void setBandGPU (int b){
        gpu.setBand(b);
        }

    public void modifyWriteSpeedMEM (int w){
        mem.modifyWrite(w);
        }
    public void modifyReadSpeedMEM (int r){
        mem.modifyRead(r);
        }
    public void setWriteSpeedMEM (int w){
        mem.setWrite(w);
        }
    public void setReadSpeedMEM (int r){
        mem.setRead(r);
        }

    public void setGPUpresence (boolean pr){
        gpu.presenceGPU(pr);
        }
    
    public void setPrice (double p){
        if(p>=0)
        price=p;
    }
    public void modifyPrice (double p){
        if(p<0 && p>price) System.err.println(" modify Error ");
        else price=p;
   }

    abstract public double Score ();
}
