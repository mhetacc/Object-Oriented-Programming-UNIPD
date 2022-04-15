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
public class RandomAccessMemory extends BaseComponent {
    private double Score (){return (getClock() + getMem());}
	 public double getScore () {return Score();}
	 
	 public void Print() {
		 double mem=getMem();
		 double memGB=mem/1024.0;
		       System.out.println("La RAM ha: "+ memGB + " GB" + ' ' + getClock() + " MHz");
	 }
         
         public RandomAccessMemory (int clock, double mem) {
             super(clock, mem);
         }
         
         public RandomAccessMemory() {} //chiamata implicita super()
}
