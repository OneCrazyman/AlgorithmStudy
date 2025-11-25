// 1043번
// 진실을 알게되는 모든 집합을 먼저 구한다
// 그 다음 진실이 속한 파티일 경우 카운팅을 제외한다

// M개 파티에서 진실 집합 구하기 = O(M*N^2)
// M개 파티에서 거짓말 가능 카운팅 = O(M*N^2)
// = O(M*N^2) = 50^3 '=. 10^4

using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;
namespace algorithm_study
{
    class main
    {
        static int N;
        static int M;
        static void Main(string[] args)
        {
            int[] nm = Console.ReadLine().Split().Select(int.Parse).ToArray();
            N = nm[0];
            M = nm[1];

            int[] truth = Console.ReadLine().Split().Select(int.Parse).ToArray();
            int truthCount = truth[0];

            HashSet<int> knowTruth = new HashSet<int>();
            for (int i = 1; i <= truthCount; i++)
            {
                knowTruth.Add(truth[i]);
            }

            List<HashSet<int>> partyList = new List<HashSet<int>>();
            for (int i = 0; i < M; i++)
            {
                int[] party = Console.ReadLine().Split().Select(int.Parse).ToArray();
                int peopleParty = party[0];
                HashSet<int> hs = new HashSet<int>();
                for (int j = 1; j <= peopleParty; j++)
                {
                    hs.Add(party[j]);
                }
                partyList.Add(hs);
            }

            bool updated = true;

            while (updated)
            {
                updated = false;
                // 집합 찾아서 업데이트
                for (int i = 0; i < M; i++)
                {
                    bool hasCommon = knowTruth.Overlaps(partyList[i]);
                    if (hasCommon)
                    {
                        foreach (var p in partyList[i])
                        {
                            bool newTruth = knowTruth.Add(p);
                            if (newTruth)
                                updated = true;
                        }
                    }
                }
            }

            int ans = 0;
            for (int i = 0; i < M; i++)
            {
                bool hasCommon = knowTruth.Overlaps(partyList[i]);
                if (!hasCommon)
                {
                    ans++;

                }
            }
            Console.WriteLine(ans);
        }
    }
}
