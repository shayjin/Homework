import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Stack;

public class Interpretor {
    public static Map<String, Integer> global;       
    public static Stack<Map<String, Integer>> stack;  
    static List<String> heap; 
    public static Map<String, String> shared;
    public static Scanner scanner;


    static void init() {
        global = new HashMap<>();
        stack = new Stack<>();
        heap = new ArrayList<>();
        shared = new HashMap<>();
    }

    public static void addContext() {
        stack.push(new HashMap<>());
    }

    public static void deleteContext() {
        stack.pop();
    }

    public static void allocate(String name, int value) {
        if (stack.isEmpty()) {
            global.put(name, value);
        } else {
            Map<String, Integer> top = stack.pop();
            top.put(name, value);
            stack.push(top);
        }
    }

    public static void allocate(String name) {
        if (stack.isEmpty()) {
            global.put(name, null);
        } else {
            Map<String, Integer> top = stack.pop();
            top.put(name, null);
            stack.push(top);
        }
    }

    public static void allocateShare(String ref, String name) {
        if (shared.containsKey(name)) {
            allocateShare(ref, shared.get(name));
        } else {
            shared.put(ref, name);
            heap.add(ref);
        }   
    }

    public static void allocateOnHeap(String name) {
        boolean contains = false;
        
        if (shared.containsKey(name)) shared.remove(name);

        for (int i = 0; i < stack.size() - 1 ; i++) {
            if (stack.get(i).containsKey(name)) {
                heap.add(name);
                contains = true;
                return;
            }
        }

        if (!contains) {
            heap.add(name);
            contains = true;
        }


        if (!contains) {
            System.out.println("Error: Assignment to a null ref variable. ");
            System.exit(-1);
        }
    }

    public static void assign(String name, int value) {
        if (!heap.contains(name)) {
            System.out.println("Error: Assignment to a null ref variable. ");
            System.exit(-1);
        }
        
        if (shared.containsKey(name)) {
            assign(shared.get(name), value);
        } else {
            for (int i = stack.size() - 1; i >= 0 ; i--) {
                if (stack.get(i).containsKey(name)) {
                    stack.get(i).put(name, value);
                    return;
                }
            }
    
            if (global.containsKey(name)) global.replace(name, value);
        }
    }

    public static int search(String name) {
        if (shared.containsKey(name)) return search(shared.get(name));

        for (int i = stack.size() - 1; i >= 0 ; i--) {
            if (stack.get(i).containsKey(name)) {
                return stack.get(i).get(name);
            }
        }

        if (global.containsKey(name)) return global.get(name);

        return 0;
    }
}
