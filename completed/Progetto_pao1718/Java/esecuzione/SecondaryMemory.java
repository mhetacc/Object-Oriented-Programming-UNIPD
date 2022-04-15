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
public class SecondaryMemory extends BaseComponent {
    private int write_speed; //MB/s
    private int read_speed;  //MB/s
    private double Score() {
        return (write_speed+read_speed+getMem()); 
        }

    public double getScore(){    //override
        return Score();
        }
    public void modifyWrite (int w){
        if(write_speed+w<0) System.err.println(" modify Error, valore inserito rende velocita' scrittura negativa "); //controlla che sia una modifica "sicura"
        else write_speed+=w;
    }
    public void modifyRead (int r){
        if(read_speed+r<0) System.err.println(" modify Error, valore inserito rende velocita' lettura negativa ");
        else read_speed+=r;
    }
    public void setWrite (int w){
        if(w>0)
        write_speed=w;
        else System.err.println(" set Error, inserire valore>0 ");
   }
    public void setRead (int r){
        if(r>0)
        read_speed=r;
        else System.err.println(" set Error, inserire valore>0 ");
    }
    
    public void Print () {    //override
    double mem=getMem()/1024.0; //da MB a GB
    System.out.println( "La memoria secondaria ha " + mem + " GB "+write_speed+" KB/s in scrittura e "+read_speed+ " KB/s in lettura");
    }
    
    public SecondaryMemory (int clock, double mem, int write, int read){
        super(clock, mem);
        write_speed=write;
        read_speed=read;
    }
    
    public SecondaryMemory () {
        write_speed=0;
        read_speed=0;
    }
}
