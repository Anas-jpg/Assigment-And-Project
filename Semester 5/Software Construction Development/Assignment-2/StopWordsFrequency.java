
package com.mycompany.assignment2;
import java.util.*;

public class StopWordsFrequency {
public StopWordsFrequency()
{
    
}
public void WordFrequency(String[] Story,String[]WordList)
{      
      //-----------------Q-5--------------------
       HashMap<String,Integer> hMap = new HashMap<>();
      int counter=0;
      for(int i = 0 ; i<WordList.length ; i++){
          counter=0;
          for(int j = 0 ; j<Story.length ; j++)
          {
              if(WordList[i].equals(Story[j]))
              {
                  counter++;
              }
          }
          
          if (counter==0)
              continue;
          else
          {
              hMap.put(WordList[i], counter);
          }
      }
      System.out.println(hMap);
   }

}




