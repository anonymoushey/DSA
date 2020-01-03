import animation.Scene;
import animation.SceneObject;
import animation.View;
import imt2018033.*;
import imt2018002.*;
import imt2018514.*;
import imt2018074.*;

import imt2018016.*;
//import imt2018016.DemoSceneObject;
import imt2018016.DemoScene;

import java.util.*;
//import test.TestObject;
//import test.TestScene;


// Driver class to set up and exercise the animation
public class Demo {

	public static void main(String[] args) {
		Scene scene = new imt2018016.DemoScene(); // replace with your implementation

		// populate the scene with objects implemented by the team
		/*
		for (int i = 0; i < 6; i++) {
			SceneObject s = new DemoSceneObject(); // replace with your implementation
			s.setPosition(i * 50, i * 50);
			scene.addObstacle(s); // using appropriate derived classes
		}

		for (int i = 0; i < 6; i++) {
			SceneObject s = new DemoSceneObject(); // replace with your implementation
			s.setPosition(500 - i * 50, 300 + i * 50); // these will be changed for the demo
			s.setDestPosition(0, 0);
			scene.addActor(s); // using appropriate derived classes
		}
		*/
		SceneObject a = new SceneObjectExtended(); //jishnu
		a.setPosition(100, 100);
		a.setDestPosition(0, 0);
		scene.addActor(a);

		SceneObject b = new imt2018514.DemoSceneObject();  //saad
		b.setPosition(200, 200);
		b.setDestPosition(500, 500);
		scene.addActor(b);

		SceneObject c = new imt2018002.TestObject(); //abhigna
		c.setPosition(400, 400);
		c.setDestPosition(0, 0);
		scene.addActor(c);
		
		/*
		SceneObject d = new imt2018016.DemoSceneObject();  //bharat
		d.setPosition(300, 300);
		d.setDestPosition(0, 0);
		scene.addActor(d);
		*/
		SceneObject e = new IMT2018046.TestObject();    //aarti
		e.setPosition(500, 500);
		e.setDestPosition(0, 0);
		scene.addActor(e);

		
		SceneObject z = new imt2018016.DemoSceneObject(); //jishnu
		z.setPosition(100, 100);
		scene.addObstacle(z);

		SceneObject x = new imt2018016.DemoSceneObject();  //saad
		x.setPosition(200, 200);
		scene.addObstacle(x);

		SceneObject y = new imt2018016.DemoSceneObject(); //abhigna
		y.setPosition(400, 400);
		scene.addObstacle(y);

		SceneObject w = new imt2018016.DemoSceneObject();  //bharat
		w.setPosition(300, 300);
		scene.addObstacle(w);

		SceneObject v = new imt2018016.DemoSceneObject();    //aarti
		v.setPosition(500, 500);
		scene.addObstacle(v);
		

		// View view = new DemoTextView();
		View view = new DemoSwingView();

		scene.setView(view);

		view.init();

	}

}
