using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Runtime.InteropServices;

namespace KodCezara
{
    unsafe class FunkcjeAsemblera
    {
        [DllImport(@"bibliotekaASM.dll", CallingConvention = CallingConvention.StdCall)]
        private extern static void testow();
        public static void testWywolania2()
        {
            testow();
        }

    }
}
