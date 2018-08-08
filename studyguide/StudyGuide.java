/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author david
 */

import java.util.Scanner;
import java.util.NoSuchElementException;
import java.io.PrintWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.util.Random;
import java.util.Arrays;
import java.io.IOException;
import java.lang.Runtime;
import java.lang.ProcessBuilder;

public class StudyGuide {

    /**
     * @param args the command line arguments
     */
    //Topics?
    //Each topic holds tests
    //Each test holds questions
    //Each question holds problem and answer
    
    //Array of missed questions for each test
    //choose to go through all questions or just missed
    
    //Study mode. Just go through each question
    //Test mode: Randomize each question
    
    //Access questions to edit test
    public Test[] tests = new Test[50];
    public int num;
    
    public StudyGuide() {
        
    }
    
    public void menu() {
        System.out.println("[1] Create New Test");
        System.out.println("[2] Take Test");
        System.out.println("[3] Load Test");
        System.out.println("[4] Study Test");
        System.out.println("[0] Exit");
    }
    
    public void create() throws FileNotFoundException{
        String file;
        Scanner sc = new Scanner(System.in);
        System.out.println("What is the name of the file?");
        file = sc.nextLine();
        
        Test t = new Test(file);
        Question qs[] = t.getTest();
        
        
        while(true) {
            try {
                System.out.println("What is the question?: ");
                String question = sc.nextLine();
                if (question.length() == 0) {
                    break;
                }
                System.out.println(question.length());
                Question q = new Question();
                q.setQ(question);
            
                System.out.println("What is the answer?");
                String answer = sc.nextLine();
                if (answer.length() == 0) {
                    break;
                }
                q.setA(answer);
            
                int index = t.getSize();
                qs[index] = q;
                t.increase();
            }
            catch(NoSuchElementException nse){
                System.out.println("No input!");
                System.exit(0);
            }
        }
        
        //For every question in test (t.getSize())
        //Write "Q: <Question>
        //      "A: <Answer>
        File out = new File(file);
        PrintWriter pr = new PrintWriter(out);
        for(int i = 0; i < t.getSize(); i++) {
            Question q = qs[i];
            pr.println("Q: " + q.getQ());
            pr.flush();
            pr.println("A: " + q.getA() + '\n');
            pr.flush();
        }
        
        pr.close();
        tests[num++] = t;
        
    }
    
    //Read file
    //Must read Question,Answer pair and store in Question object
    //question object must be stored in test object
    //test object then stored in tests array
    public void readFile(String s) throws FileNotFoundException {
        //String filename = tests[t].getName();
        String filename = s;
        File file = new File(filename);
        Test t = new Test(filename);
        Scanner sc = new Scanner(file);
        int i = 0;
        while(sc.hasNextLine()) {
            String line = sc.nextLine();
            if(line.equals("")) {
                continue;
            }
            Scanner l = new Scanner(line);
            Question q = new Question();
            if(line.substring(0, 3).equals("Q: ")){
                q.setQ(line.substring(3));
            }
            line = sc.nextLine();
            if (line.substring(0, 3).equals("A: ")) {
                q.setA(line.substring(3));
            }
            
            t.setQuestion(q, i++);
            t.increase();
        }
        
        tests[num++] = t;
        
    }
    
    //take a test
    //first choose a test
    //then cycle through questions
    //get random number
    //if question has been answered 
    public void takeTest(int c) throws IOException{
        Test t = tests[c];
        Random rand = new Random();
        Boolean answered[] = new Boolean[100];
        Arrays.fill(answered, false); 
        Scanner sc = new Scanner(System.in);
       
        for(int i = 0; i < t.getSize(); i++) {
            int n = rand.nextInt(t.getSize());
            if(!answered[n]) {
                Question q = t.getQuestion(n);
                System.out.print(n + ": " + q.getQ());
                //do this
                sc.nextLine();
                
                //System.out.print("\b\b");
                //Runtime.getRuntime().exec("clear");
                
                System.out.print(n + ": " + q.getA());
                sc.nextLine();
                answered[n] = true;
                
            }
            else{
                i--;
            }
        }
    }
    
    public void studyTest(int c) {
        Test t = tests[c];
        Scanner sc = new Scanner(System.in);
        for(int i = 0; i < t.getSize(); i++) {
            Question q = t.getQuestion(i);
            System.out.print(i + ": " + q.getQ());
            sc.nextLine();
            System.out.println(q.getA() + '\n');
        }
        
    }
    
    //choose question
    //choose q or a
    //change them
    //TODO: figure out how to edit stream
    public void editTest(int c) {
        
    }
    
    //choose a test
    public int chooseTest() {
        System.out.println("Tests:");
        
        for(int i = 0; i < num; i++) {
            System.out.println("Test[" + i + "]: " + tests[i].getName());
        }
        
        System.out.println("Choose test: ");
        
        int t;
        Scanner sc = new Scanner(System.in);
        t = sc.nextInt();
        
        return t;
        
        
    }
    
    public void randomize(){
        Random rand = new Random();
        Boolean answered[] = new Boolean[100];
        java.util.Arrays.fill(answered, false);
        int answers[] = new int[100];
  
        for(int i = 0; i < 100; i++) {
            int n = rand.nextInt(100);
            if(!answered[n]){
                System.out.println((i+1) + ": " + n);
                answered[n] = true;
                answers[i] = n;
            }
            else {
                i--;
            }
                    
        }
        
        Arrays.sort(answers);
        
        for(int i = 0; i < answers.length; i++) {
            
            System.out.println(answers[i]);
        }
    }
    
    //Want to create test files
    //Creation must be dynamic (delete question, go back, cycle through question)
    public static void main(String[] args) {
        // TODO code application logic here
        //Scanner sc = new Scanner(System.in);
        StudyGuide s = new StudyGuide();
        
        while(true) {
            s.menu();
            try {
                Scanner sc = new Scanner(System.in);
                int c;
                System.out.println("Select a command");
                c = sc.nextInt();
                sc.nextLine();

                switch(c) {
                    case(1):
                        System.out.print("\033[H\033[2J");
                        System.out.flush();
                        s.create();
                        continue;

                    case(2):
                        System.out.print("\033[H\033[2J");
                        System.out.flush();
                        int t = s.chooseTest();
                        s.takeTest(t);
                        continue;
                        
                    case(3):
                        System.out.print("\033[H\033[2J");
                        System.out.flush();
                        System.out.println("What is the name of the file:");
                        String f = sc.nextLine();
                        s.readFile(f);
                        continue;
                        
                    case(4):
                        System.out.print("\033[H\033[2J");
                        System.out.flush();
                        int st = s.chooseTest();
                        s.studyTest(st);
                        continue;
                        
                    case(5):
                        System.out.print("\033[H\033[2J");
                        System.out.flush();
                        break;
                        

                    default:
                        Runtime.getRuntime().exec("sh -c clear");
                        System.out.println("Exiting program!");
                        break;
                }
            }
            catch (FileNotFoundException fnf) {
                System.out.println("File Not Found!");
            }
            catch(IOException io){
                System.out.println("IO Exception");
            }
            //System.out.println("Done!\n");

            //s.randomize();
            break;
        }
        
        
    }
    
}
