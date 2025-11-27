using System;
using System.Collections;
using System.Collections.Generic;
public class Solution {
    public int[] solution(int[] array, int[,] commands) {
        List<int> ans = new List<int>();
        int len = commands.GetLength(0);
        for(int i=0; i<len;i++){
            int s = commands[i,0];
            int e = commands[i,1];
            int k = commands[i,2];
            // Console.WriteLine($"{s}{e}{k}");
            int range = e-s+1;
            // insert
            int[] arr = new int[range];
            for(int j=0;j<range;j++){
                arr[j] = array[s-1];
                s++;
            }
            // sort
            Array.Sort(arr);
            // foreach (int o in arr){
            //      Console.Write(o);
            // }
            // Console.WriteLine();
            ans.Add(arr[k-1]);
        }
        
        return ans.ToArray();
    }
}