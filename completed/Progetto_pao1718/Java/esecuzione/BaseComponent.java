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
public abstract class BaseComponent implements Component {
    private int clockspeed; //MHz
    private double memory_dimension; //MB

    public int getClock(){
        return clockspeed;}

    public double getMem (){
        return memory_dimension;}

    public void modifyMemory (double mem){
        if((memory_dimension+mem)>0)
        memory_dimension+=mem;
        else System.err.println(" set Error, inserire valore>0 ");
   }
    public void modifyClock (int c){
        if((clockspeed+c)<0) 
        System.err.println(" modify Error, valore inserito comporta clock negativo ");
        else clockspeed+=c;
   }
    public void setMemory (double mem){
        if(mem>0)
        memory_dimension=mem;
        else System.err.println(" set Error, inserire valore>0 ");
    }
    public void setClock (int c){
        if(c>0)
        clockspeed=c;
        else System.err.println(" set Error, inserire valore>0 ");
    }
    
    public BaseComponent (int clock, double mem){
        clockspeed=clock;
        memory_dimension=mem;
    }
    
    public BaseComponent (){
        clockspeed=0;
        memory_dimension=0;
    }
}
