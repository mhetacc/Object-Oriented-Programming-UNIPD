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
public class Screen implements Component {
    private double pscore() {
        if(dimension>0){
            //System.out.println("Screen::pscore()  res=" +getRes());
            //System.out.println("Screen::pscore()  dimension(int)=" +(int)dimension);
            return getRes()/dimension;
        
        }
        else {
            System.err.println("Errore: tentativo di ottenere score con schermo con dimensione <=0");
            return 0;
        }
    }
    private int resWidth;  //pixels
	    private int resHeight;  //pixels
	    private double dimension;  //diagonal inches
	    
	    public void setRes (int w, int h){  //w= larghezza   h= altezza 
	    	if(w>=0 && h>=0){
	    	    resWidth=w;
	    	    resHeight=h;
	    	    }
	    	    else System.err.println("Input error, inserire valori >=0");
	    }
	    
	    public void setDim (double dim){
	    	if(dim>=0)
	            dimension=dim;
	        else System.err.println("Input error, inserire valore >=0");
	    }
	    
	    public int getRes() {return resWidth*resHeight;}
	    public double getDim () {return dimension;}
	    public int getResW() {return resWidth;}
	    public int getResH() {return resHeight;}
	    public double getScore() {return pscore();}   //override
	    
	    public void Print() {  //override
	    	System.out.println("Risoluzione schermo= "+resWidth+" X "+resHeight);
	        System.out.println("Dimensione schermo= "+dimension);
	    }
            
            public Screen(int resW, int resH, double dim){
                resWidth=resW;
                resHeight=resH;
                dimension=dim;
            }
            
            public Screen(){
                resWidth=0;
                resHeight=0;
                dimension=0;
            }
}
