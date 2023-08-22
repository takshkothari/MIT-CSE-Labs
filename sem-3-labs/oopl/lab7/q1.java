import com.course.structure.Building;

class q1 {
    public static void main(String args[]) {

        Building b = new Building();
        Building.House h = b.new House();
        Building.School s = b.new School();

        b.getBuilding();
        b.showBuilding();
        h.getHouse();
        h.showHouse();
        s.getSchool();
        s.showSchool();
    }
}