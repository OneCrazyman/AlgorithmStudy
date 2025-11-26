// 프로그래머스 - 해시 - 의상

// 각 종류별 하나씩 꺼내서 조합한다 -> 경우의 수 (안꺼내는것도 포함하니, 총갯수+1씩 곱할것)
// 해시셋으로 각 sort별 리스트를 생성하고 -> 리스트에 옷을 add
// 마지막으로 해시셋 순회 -> 경우의 수 계산

using System;
using System.Collections.Generic;
using System.Linq;
public class Solution {
    
    Dictionary<string,List<string>> dic = new Dictionary<string,List<string>>();
    
    public int solution(string[,] clothes) {
        InsertToDictionary(clothes);
        return MakeAnswer();
    }
    
    private void InsertToDictionary(string[,] clothes){
        int rowNum = clothes.GetLength(0);
        for (int i=0; i<rowNum ;i++){
            string item = clothes[i,0];
            string type = clothes[i,1];
            if (!dic.ContainsKey(type)){
                dic[type] = new List<string>();
            }
            var list = dic[type];
            list.Add(item);
        }
        return;
    }
    
    private int MakeAnswer(){
        int answer=1;
        
        foreach (var pair in dic){
            var list = pair.Value;
            answer *= list.Count + 1;
        }
        
        return answer - 1;
    }
}
