using System;
using System.Collections.Generic;
using System.Linq;

public class Solution
{
    public int[] solution(int[] progresses, int[] speeds)
    {
        int[] answer = new int[] { };

        var tmp = progresses.Select((item, idx) => (int)Math.Ceiling( (double)(100 - item) / speeds[idx] ));

        List<int> deploy = new List<int>();
        List<int> Remains = new List<int>();

        int lastBig = -1;
        foreach(int itm in tmp)
        {
            if (lastBig < itm)
                lastBig = itm;

            deploy.Add(lastBig);
        }

        var tmp2 = from itm in deploy
                   group itm by itm into g
                   select new
                   {
                       CNT = g.Count()
                   };

        answer = tmp2.Select(x => x.CNT).ToArray();

        return answer;
    }
}
