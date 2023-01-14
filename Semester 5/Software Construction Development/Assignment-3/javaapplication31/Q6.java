/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package javaapplication31;

import java.util.*;

/**
 *
 * @author hp
 */
public class Q6 {
    private String[] allStrings;
    private HashMap<String, Integer> stopWords = new HashMap<>();
    private String checkString;
    
    public Q6()
    {
           checkString="In a spell of dry weather, when the Birds could find very little to drink, a thirsty Crow found a pitcher with a little water in it. But the pitcher was high and had a narrow neck, and no matter how he tried, the Crow could not reach the water. The poor thing felt as if he must die of thirst.\n" +
"\n" +
"Then an idea came to him. Picking up some small pebbles, he dropped them into the pitcher one by one. With each pebble the water rose a little higher until at last it was near enough so he could drink.\n" +
"\n" +
"In a pinch a good use of our wits may help us out.";
           allStrings=new String []{"i",
            "me", "my", "myself", "we", "our", "ours", "ourselves", "you", "your",
            "yours", "yourself", "yourselves", "he", "him", "his", "himself", "she",
            "her", "hers", "herself", "it", "its", "itself", "they", "them",
            "their", "theirs", "themselves", "what", "which", "who", "whom", "this",
            "that", "these", "those", "am", "is", "are", "was", "were", "be",
            "been", "being", "have", "has", "had", "having", "do", "does", "did",
            "doing", "a", "an", "the", "and", "but", "if", "or", "because", "as",
            "until", "while", "of", "at", "by", "for", "with", "about", "against",
            "between", "into", "through", "during", "before", "after", "above",
            "below", "to", "from", "up", "down", "in", "out", "on", "off", "over",
            "under", "again", "further", "then", "once", "here", "there", "when",
            "where", "why", "how", "all", "any", "both", "each", "few", "more",
            "most", "other", "some", "such", "no", "nor", "not", "only", "own",
            "same", "so", "than", "too", "very", "s", "t", "can", "will", "just",
            "don", "should", "now"};
  }
  public void printStop()
  {
     initializeHash();
     System.out.print(stopWords.get("trdfg"));
         
      
  }
  public void initializeHash()
  {
      for(int i=0;i<allStrings.length;i++)
      {
          stopWords.put(allStrings[i], 0);    
      }
      
  }
  public void addFrequency()
  {
      String[] result = checkString.split(" ");
      for(int i=0;i<result.length;i++)
      {
          String key=result[i];
          if(stopWords.get(key)!=null)
          {
              int temp=stopWords.get(key);
              temp++;
              stopWords.put(key, temp);           
          }
          
      }
  }
  public void printHash()
  {
    System.out.println("Following stop words occurs following times");
    for ( String key : stopWords.keySet() ) {
    if(stopWords.get(key)!=0)
    {
        System.out.println(key+": "+stopWords.get(key));
    }
                
}
      
  }
  public void myQuestion()
  {
      initializeHash();
      
      addFrequency();
      printHash();
  
  }
  
    
    
    
}
