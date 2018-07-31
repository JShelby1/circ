using System;
namespace Circle
{
    public static class ExtensionMethods
    {
        public static int RoundOff(this int i)
        {
            return ((int)Math.Round(i / 10.0)) * 10;
        }
    }

}
