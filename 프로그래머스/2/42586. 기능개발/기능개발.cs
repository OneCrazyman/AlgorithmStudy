// 프로그래머스 - 기능개발

// 작업이 끝나기까지 남은 일수를 계산 [v]
// 각 작업 순서때 자기보다 일자가 낮으면 카운트+1 ,높아지면 다음 배포로 넘어가고 반복 []

using System;
using System.Collections.Generic;

public class Solution {
    public int[] solution(int[] progresses, int[] speeds) {
        List<int> answer = new List<int>();
        
        // Calculate
        int count = 0;
        int prevday = 0;
        for(int i=0; i<progresses.Length; i++){
            int pro = progresses[i];
            int speed = speeds[i];
            int day = (100-pro)/speed;
            if (day*speed<100-pro) day++;
            
            // Counting
            if (day > prevday){
                answer.Add(count);
                count=1;
                prevday = day;
            }
            else{
                count++;   
            }            
            // Console.WriteLine(day);
        }
        answer.Add(count);
        answer.RemoveAt(0);
        
        return answer.ToArray();
    }

}