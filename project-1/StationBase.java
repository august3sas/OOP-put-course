
import java.util.Scanner;
import java.io.File;
//import java.io.FileNotFoundException;
import java.io.IOException;
public class StationBase {
    public int[] entryArray = new int[239];
    public int[] exitArray = new int[220];
    public String[] stationNames = new String[28];
    public int[] stationID = new int[28];
    public void debug()
    {
        for(int i=0;i<239;i++){System.out.printf("%d ",entryArray[i]);}System.out.println();
        for(int i=0;i<220;i++){System.out.printf("%d ",exitArray[i]);}System.out.println();
        for(int i=0;i<28;i++){System.out.printf("%s \n",stationNames[i]);}System.out.println();
        for(int i=0;i<28;i++){System.out.printf("%d ",stationID[i]);}System.out.println();
        System.out.println("END_DEBUG");
    }
    public StationBase()
    {
        try
        {
           File f = new File("db_tstops.txt");
           Scanner cin= new Scanner(f);
           int ctin=0,ctout=0;
           for(int i=0;i<28;i++)
           {
                stationID[i]=cin.nextInt();
                stationNames[i]=cin.next();
                int prob=cin.nextInt();
                for(int j=0;j<prob;j++)
                {
                    entryArray[ctin]=stationID[i];
                    ctin++;
                }
                int prob1=cin.nextInt();
                for(int j=0;j<prob1;j++)
                {
                    exitArray[ctout]=stationID[i];
                    ctout++;
                }
           }
           cin.close();
           //debug();
        }
        catch(IOException f)
        {
            System.out.println("XD");
            f.printStackTrace();
        }
    }
    public int returnIndexOfElement(String x)
    {
        for(int i=0;i<stationNames.length;i++)
        {
            if(x.equals(stationNames[i]))
            {
                return i+1;
            }
        }
        return -1;
    }

}
