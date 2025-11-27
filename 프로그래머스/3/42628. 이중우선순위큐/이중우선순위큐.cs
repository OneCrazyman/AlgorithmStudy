// 이중 우선순위 큐

// input 분리 switch-> 확인 [v]
// insert시 max,min힙에 둘다 저장 // PriorityQueue 사용불가 -> SortedDictionary로 변경
// 

using System;
using System.Collections.Generic;
using System.Linq;
public class Solution {
    SortedDictionary<int,int> map = new SortedDictionary<int,int>();
    public int[] solution(string[] operations) {
        // PriorityQueue<int,int> maxheap = new PriorityQueue<int,int>(); // val,-val
        // PriorityQueue<int,int> minheap = new PriorityQueue<int,int>(); // val,+val
        
        for (int i=0; i<operations.Length; i++){
            string[] input = operations[i].Split();
            char type = char.Parse(input[0]);
            int val = int.Parse(input[1]);
            switch (type){
                case 'I':
                    // Console.WriteLine($"I {type}:{val}");
                    Insert(val);
                    break;
                case 'D':
                    if (val==1){
                        // Console.WriteLine($"1 {type}:{val}");
                        DeleteMax();
                    }
                    else{
                        // Console.WriteLine($"-1 {type}:{val}");
                        DeleteMin();
                    }
                    break;
            }
        }
        
        if (map.Count == 0){
            return new int[] {0,0};
        } else{
            return new int[] {map.Last().Key, map.First().Key};
        }
    }
    void Insert(int x){
            if (!map.ContainsKey(x)) map[x] = 0;
            map[x]++;
        }
        
        void DeleteMin(){
            if (map.Count == 0) return;
            int key = map.First().Key;
            if (map[key] == 1) map.Remove(key);
            else map[key]--;
        }
        
        void DeleteMax(){
            if (map.Count == 0) return;
            int key = map.Last().Key;
            if (map[key] == 1) map.Remove(key);
            else map[key]--;
        }
        
}