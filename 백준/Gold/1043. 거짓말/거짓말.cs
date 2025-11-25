// 1043번

// 유니온파인드
// 진실을 알고있는 노드의 부모노드 값을 0으로, 각 파티구성원들끼리 union한다.
// union 구현시 부모 노드 값이 작은것이 큰값을 대체하도록 한다. (그래야 최종적으로 부모노드가 0이 되기때문)
// 유니온 파인드 후, 파티리스트를 순회하며 아무 노드를 find한 결과가 0이 아니여야 거짓말 가능한 집단이므로 카운트한다.

// 파티 M번당, 최대 N개끼리 Union
// => O(M*N) = 50^2

using System;
using System.Collections.Generic;
using System.Linq;
using System.Security.Policy;

namespace algorithm_study
{
    class main
    {
        static void Union(int s,int e) {
            s = Find(s);
            e = Find(e);

            if (s > e)
                parent[s] = e;
            else
                parent[e] = s;
        }

        static int Find(int n)
        {
            if (n != parent[n])
            {
                parent[n] = Find(parent[n]);
            }
            return parent[n];
        }

        const int MAX_LEN = 50;
        static int[] parent = new int[MAX_LEN + 1];
        static void Main(string[] args)
        {
            int[] nm = Console.ReadLine().Split().Select(int.Parse).ToArray();
            int N = nm[0];
            int M = nm[1];

            int[] truth = Console.ReadLine().Split().Select(int.Parse).ToArray();
            int truthCount = truth[0];

            int[] knowTruth = new int[truthCount];
            for (int i = 1; i <= truthCount; i++)
            {
                knowTruth[i-1] = truth[i];
            }
            int[][] partyArr = new int[M][];
            for (int i = 0; i < M; i++)
            {
                int[] party = Console.ReadLine().Split().Select(int.Parse).ToArray();
                int partyCount = party[0];
                partyArr[i] = new int[partyCount];
                for (int j = 1; j <= partyCount; j++)
                {
                    partyArr[i][j-1] = party[j];
                }
            }

            // 유니온파인드전 초기화
            for (int i=1; i<=N; i++)
            {
                parent[i] = i;
            }

            foreach (var know in knowTruth)
            {
                parent[know] = 0;
            }

            for (int i=0; i<M; i++)
            {
                int len = partyArr[i].Length;
                for (int j=0; j<len-1; j++)
                {
                    Union(partyArr[i][j], partyArr[i][j+1]);
                }
            }

            int ans = 0;
            for (int i=0; i<M; i++)
            {
                int result = Find(partyArr[i][0]);
                if (result != 0)
                {
                    ans++;
                }
            }
            Console.WriteLine(ans);
        }
    }
}
