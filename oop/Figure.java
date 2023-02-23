import java.util.*;

abstract class Figure {
    private String name;
    private String color;

    public Figure(String name, String color){
        this.name = name;
        this.color = color;
    }

    public String getName(){
        return name;
    }

    public String getColor(){
        return color;
    }

    public boolean equals(Object o){
        return( o instanceof Figure) && (((Figure)o).name == getName() && ((Figure)o).color == getColor());
    }

    abstract public double getArea();

} 

class Square extends Figure{
    private double area;

    public Square(String name, String color, double area){
        super(name, color);
        this.area = area;
    }

    public double getArea(){
        return this.area;
    }
}

class Rectangle extends Figure{
    private double width;
    private double length;

    public Rectangle(String name, String color){
        super(name, color);
    }

    public void setWidth(double width){
        this.width = width;
    }

    public void setLength(double length){
        this.length = length;
    }

    public double getWidth(){
        return this.width;
    }

    public double getLength(){
        return this.length;
    }

    public double getArea(){
        return this.width * this.length;
    }

}

class Folder{
    ArrayList<Figure> arr = new ArrayList<Figure>();

    public void addFigure(Figure fig) throws AlreadyAdded{
        if(!arr.contains(fig)){
            arr.add(fig);
        }
        for(int i = 0; i <= arr.size(); i++){
            if(arr.get(i).equals(fig)){
                throw new AlreadyAdded();
            }
        }
    }

    public boolean isInFolder(Condition condition){
        for(Figure fig : arr){
            if(condition.compliesToCondition(fig) == true)
                return true;
        }
        return false;
    }

    public String toString(){
        StringBuilder list = new StringBuilder();

        for(Figure fig : arr){
            list.append(fig);
        }
        return list.toString();
    }
}

class AlreadyAdded extends Exception{
    public AlreadyAdded(){
        super("Already added!");
    }
}

interface Condition{
    public boolean compliesToCondition(Figure fig);
}

class AreaColorCondition implements Condition{
    private String color;

    public AreaColorCondition(String color){
        this.color = color;
    }

    public boolean compliesToCondition(Figure fig){
        return((fig.getArea() == 50) && (fig.getColor() == this.color));
    }

}

class NameColorCondition implements Condition{
    private String name;

    public NameColorCondition(String name){
        this.name = name;
    }

    public boolean compliesToCondition(Figure fig){
        return((fig.getName() == this.name) && (fig.getColor() == "blue"));
    }
}

class Main{
    public static void main(String[] args){
        System.out.println("It's working!");
    }
}
