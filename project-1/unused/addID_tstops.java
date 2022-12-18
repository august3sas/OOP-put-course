package unused;
import java.util.Scanner;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.FileWriter;
public class addID_tstops
{
    public static void main(String[] args)
    {
        try
        {
            File fl = new File("database/db_tstops.txt");
            FileWriter flout = new FileWriter("database/db_tstops_parsed.txt");
            Scanner in=new Scanner(fl);
            int ct=0;
            while(in.hasNextLine())
            {
                String stacja=in.nextLine();
                /*if(stacja.contains("GPOINT")==false)
                {*/
                    flout.write(stacja+" "+ct+"\n");
                    ct++; 
                /* }
                else
                {
                    flout.write(stacja+"\n");
                }*/
            }
            in.close();
            flout.close();
        }
        catch(FileNotFoundException e)
        {
            System.out.println("XD");
            e.printStackTrace();
        }
        catch(IOException e)
        {
            e.printStackTrace();
        }
    }
}