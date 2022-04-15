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
public class Use {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        Computer p=new Tower(4000, 1600,  3000, 12, 4000, 16000, 500000000,6, 1500,true, true, 200, 2500, 3000, 1300);
        p.Print();
        System.out.println("--------------------------------");
        p=new Tower();
        p.Print();
        System.out.println("--------------------------------");
        p=new Laptop();
        p.Print();
        //System.out.print("Lo score e': ");
        //System.out.println(""+p.Score());
        System.out.println("--------------------------------");
        p=new Smartphone();
        p.Print();
        System.out.println("--------------------------------"); 
        
        p=new Tower();
        
        p.setCoresCPU(6);
        p.setClockCPU(4000);
        p.setMemCPU(12);
        p.setHyperCPU(true);
        
        p.setClockRAM(3000);
        p.setMemRAM(16000);
        
        p.setClockGPU(1500);
        p.setMemGPU(6000);
        p.setCoresGPU(1000);
        p.setBandGPU(250);
        p.setGPUpresence(true);
        
        p.setMemMEM(500000000);
        p.setWriteSpeedMEM(3000);
        p.setReadSpeedMEM(2500);
        
        p.setPrice(1300);
        
        
        p.Print();
        System.out.print("Lo score e': ");
        System.out.println(""+p.Score());
        
        System.out.println("--------------------------------");
        
        
        p=new Laptop();
        
        p.setCoresCPU(4);
        p.setClockCPU(3000);
        p.setMemCPU(12);
        p.setHyperCPU(true);
        
        p.setClockRAM(2500);
        p.setMemRAM(8000);
        
        p.setMemMEM(500000000);
        p.setWriteSpeedMEM(3000);
        p.setReadSpeedMEM(2500);
        
        ((Laptop)p).setBattery(9000);
        ((Laptop)p).setDimension(13.3);
        ((Laptop)p).setResolution(1920, 1080);
        ((Laptop)p).setWeight(1500);
        
        p.setPrice(800);
        
        p.Print();
        System.out.print("Lo score e': ");
        System.out.println(""+p.Score());
        
        System.out.println("--------------------------------");
        
        p=new Smartphone();
        
        p.setCoresCPU(8);
        p.setClockCPU(2000);
        p.setMemCPU(4);
        p.setHyperCPU(true);
        
        p.setClockRAM(2500);
        p.setMemRAM(4000);
        
        p.setMemMEM(64000);
        p.setWriteSpeedMEM(3000);
        p.setReadSpeedMEM(2500);
        
        ((Smartphone)p).setBattery(3000);
        ((Smartphone)p).setDimension(5.5);
        ((Smartphone)p).setResolution(1920, 1080);
        ((Smartphone)p).setWeight(200);
        
        ((Smartphone)p).setGen(4);
        
        p.setPrice(600);
        
        p.Print();
        System.out.print("Lo score e': ");
        System.out.println(""+p.Score());

        System.out.println("--------------------------------");
        
        // ESMPIO DEL FUNZIONAMENTO DEI METODI DI MODIFICA
        
        p=new Tower(1000, 1000,  1000, 10, 1000, 10000, 100000000,1, 1000,true, true, 100, 1000, 1000, 1000);
        p.modifyBandGPU(50);
        p.modifyClockCPU(200);
        p.modifyClockGPU(300);
        p.modifyClockRAM(5000);
        p.modifyCoresCPU(5);
        p.modifyCoresGPU(400);
        p.modifyMemCPU(2);
        p.modifyMemGPU(200);
        p.modifyMemMEM(555);
        p.modifyMemRAM(963);
        p.modifyPrice(60);
        p.modifyReadSpeedMEM(33);
        p.modifyWriteSpeedMEM(33);
        
        p.Print();
        System.out.print("Lo score e': ");
        System.out.println(""+p.Score());
        
        System.out.println("--------------------------------");
        
        p=new Laptop(1000, 1000,  1000, 10, 1000, 10000, 100000000,1, 1000,true, true, 100, 1000, 1000, 1000, 1920, 1080, 16, 5000, 1000);
        ((Laptop)p).modifyBattery(333);
        ((Laptop)p).modifyWeight(777);
        
        p.Print();
        System.out.print("Lo score e': ");
        System.out.println(""+p.Score());
        
        System.out.println("--------------------------------");

    }
    }
    
/**
 * CPU ha: clockspeed in MHz [int],  memoria cache in MB [double],  numero cores e' un intero [int]. Se ha hyperthreading o meno viene espresso con un booleano. 
 * GPU ha: clockspeed in MHz [int],  memoria ram DDR5 in MB [double],  numero cores e' un intero [int],  la banda e' in GB/s [int],  la presenza di una gpu dedicata o meno e' un booleano.
 * RAM ha: clockspeed in MHz [int],  meoria disponible in MB [double].
 * Memoria Secondaria (HDD o SSD) ha: memoria disponibile in MB [double],  velocita' scrittura e lettura in MB/s  [int].
 * Schermo ha:  risoluzione orizzontale e verticale in pixel (es: 1920X1080)  [int],  dimensione diagonale in pollici [double].
 * Laptop ha:  schermo [Screen], quanita' batteria in mAh [int],  peso in grammi [int].
 * Smartphone ha:  schermo [Screen], peso in grammi  [int], generazione di telefono espressa come 1G, 2G, 3G, 4G eccetera  [int].
 */
 
