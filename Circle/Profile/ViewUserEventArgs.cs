using System;
namespace Circle
{
    public class ViewUserEventArgs : EventArgs
    {
        public int Position { get; private set; }

        public ViewUserEventArgs(int position)
        {
            Position = position;
        }
    }
}
