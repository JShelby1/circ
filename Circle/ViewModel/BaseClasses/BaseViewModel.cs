using System;
using System.ComponentModel;
using System.Runtime.CompilerServices;
using System.Threading.Tasks;

namespace Circle
{
    public class BaseViewModel : INotifyPropertyChanged
    {

        public event PropertyChangedEventHandler PropertyChanged;

        public BaseViewModel ParentViewModel { get; set; } = null;

        public BaseViewModel() {}

        public BaseViewModel(BaseViewModel parentViewModel) { ParentViewModel = parentViewModel; }

        protected void OnPropertyChanged<T>(string propertyName = null)
        {
            var handler = PropertyChanged;
            if ((handler != null) && (propertyName != null))
            {
                handler(this, new PropertyChangedEventArgs(propertyName));
            }
        }

        protected void SetProperty<T>(T value, ref T backField)
        {
            backField = value;
            OnPropertyChanged<T>();
        }
  
    }
}
