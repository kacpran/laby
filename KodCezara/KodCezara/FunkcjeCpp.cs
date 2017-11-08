using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Runtime.InteropServices;
using System.Threading.Tasks;

namespace KodCezara
{
    class FunkcjeCpp
    {
        [DllImport(@"BibliotekaCPP.dll")]
        private static extern void test();
        public static void testWywolania()
        {
            test();
        }
    }
}
