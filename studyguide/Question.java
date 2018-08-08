/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author david
 */
public class Question {
    public String q;
    public String a;
    
    public Question(){
        
    }
    
    public Question(String q, String a){
        this.q = q;
        this.a = q;
    }
    
    public String getA() {
        return this.a;
    }
    
    public String getQ() {
        return this.q;
    }
    
    public void setQ(String s){
        this.q = s;
    }
    
    public void setA(String s) {
        this.a = s;
    }
    
}
