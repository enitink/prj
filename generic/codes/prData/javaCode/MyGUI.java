import java.awt.*;

class MyGUI
{
    public static void main(String [] args)
    {
        Frame F = new Frame("My First Application on GUI");
        F.setLayout(new GridLayout(5,6));
        Button B1 = new Button("OK");
        Button B2 = new Button("Hello");
        Button B3 = new Button("Cancel");
        Label L = new Label("Just see this as it's buttons don't function as it's my first one");
        
        F.add(B1);
        F.add(B2);
        F.add(B3);
        F.add(L);
        
        F.setSize(600,600);
        F.setVisible(true);
    }
}