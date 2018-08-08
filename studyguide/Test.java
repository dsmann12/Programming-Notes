/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author david
 */
public class Test {
    
    public Question[] q = new Question[500];
    public int size = 0;
    public String name;
    
    public Test() {
        
    }
    
    public Test(String n) {
        name = n;
    }
    
    public int getSize(){
        return this.size;
    }
    
    public void increase(){
        this.size++;
    }
    
    public Question getQuestion(int i) {
        return q[i];
    }
    
    public void setQuestion(Question q, int i) {
        this.q[i] = q;
    }
    
    public Question[] getTest() {
        return this.q;
    }
    
    public String getName() {
        return this.name;
    }
    
    public void setName(String s) {
        this.name = s;
    }
    
}
