using System;
using System.Collections.Generic;
using System.Text;

namespace Circle
{
    public static class Utilities
    {
        public static string ConvertMetersToFeet(string strMeters)
        {
            double feet = 0;
            double meters = 0;

            if (double.TryParse(strMeters, out meters))
                feet = meters * 3.2808399;

            return feet.ToString();
        }

    }
}
