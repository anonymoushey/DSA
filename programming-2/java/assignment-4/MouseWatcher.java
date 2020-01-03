public interface MouseWatcher{
        public void onEnter();
        public void onExit();
        public void moveTo(int x, int y);
        public void onClick(int x, int y);
        public Widget getWidget();

}