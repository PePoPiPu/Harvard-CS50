# Pocket Galaxy
#### Video Demo: https://youtu.be/jOvUn5R2_RQ
#### Description: Three.js App that creates a customizable galaxy

## 1. Introduction: What is Pocket Galaxy?
 Pocket Galaxy is a web-based app implemented in JavaScript using the Three.js JavaScript library. It consits of a 3D rendered galaxy that can be customized in the 4 following ways:
1. You can change the size of the galaxy.
2. You can set the number of arms you want your spiral galaxy to have.
3. You can change the base color of the galaxy.
4. You can customize the color of the center of your galaxy.

### 1.1 App characteristics:
 This pocket galaxy has a set of characteristics that have been implemented either through JavaScript, GSAP, CSSRulePlugin, gui.dat or through the use of Three.js postprocessing features. This characteristics are:
1. An animated introductory view of the app using a combination of JavaScript, GSAP and CSSRulePlugin.
2. An animated transition from the introductory view to the close-up view of the galaxy that has been implemented with a combination of JavaScript, GSAP and Three.js camera coordinates.
3. A bloom effect implemented with postprocessing features from Three.js
4. A simple interactive GUI implemented with gui.dat.
5. Full galaxy customization through the use of several functions implemented with JavaScript.
 How these characteristics were implemented plus their functionality and code will be explained further down this document.

## 2. Project's file structure:
```
├── project
│   ├── bundler
│   │   ├── webpack.common.js
│   │   ├── webpack.dev.js
│   │   ├── webpack.prod.js
│   ├── node_modules
│   │   ├── contains all the modules
│   ├── src
│   │   ├── index.html
│   │   ├── script.js
│   │   ├── styles.css
│   ├── static
│   │   ├── star.png
│   ├── package-lock.json
│   ├── package.json
│   ├── README.md
```
 The most important files we're going to see in this project are:
1. The src folder containing our main code including the script, the stylesheet and the html file.
2. The static folder containing a 10px by 10px png file for our custom star texture.

I believe this file structure is organized and simple to understand.

## 3. Project's implementation:
### 3.1 Installation of packages
Through the design process for this project and the required research for it, I came to know the packages I needed. In order for this, I had to execute several commands to install them. I installed through my bash terminal the Node.Js runtime environment while in the testing and learning stages. These are the main packages I installed.
```
project@ /workspaces/119201937/project
├── dat.gui@0.7.9
├── gsap@3.11.5
├── three@0.126.1
```
### 3.2 The basic setting:
Let's start by explaining how the project started: I wanted to have a customizable galaxy (a 3D object) in a region of space. For that, I had to first create a canvas for everything to render on:

```
    <canvas class="webgl"></canvas>
```
I used the following CSS settings for the html document and its body:
```
*
{
    margin: 0;
    padding: 0;
}

html,
body {
  margin: 0;
  padding: 0;
  overflow: hidden;
  height: 100vh;
  font-family: 'Inter', sans-serif;
  color: white;
}
```

And the following settings for the canvas so it could be properly positioned:
```
.webgl {
  display: block;
  position: fixed;
  top: 0;
  left: 0;
  outline: none;
}
```

Good! Now I had something to render on so I started with my main script.js file, starting with the imports:
```
import './styles.css';
import * as THREE from 'three';
```
I imported the styles sheet and the complete Three.js library. Afterwards, I started by selecting my canvas, declaring the scene and setting my main camera constructor and its position:
```
const canvas = document.querySelector('canvas.webgl');

const scene = new THREE.Scene();

const camera = new THREE.PerspectiveCamera(75, window.innerWidth / window.innerHeight, 0.1, 10000);
camera.position.set(0, 70, 200);
```
I set my camera to a FOV of 75, the aspect ratio to the window's inner Width divided by its innerHeight the camera frustrum near plane to 1 and the far plane to 10000.

Then I had to render everything by creating a function and calling it:
```
// Animation loop
function animate() {
  requestAnimationFrame(animate);

  composer.render();
}

animate();
```
>Note that I passed a composer.render() function. This is a piece of code of the final result, that's why there's a postprocessing snippet there.

Great! I saw only black. Of course, I had no object to be seen. I did encounter a problem, when resizing the window: the canvas didn't seem to adjust to that resize so I had to create a function to handle that:
```
function handleWindowResize() {
  renderer.setSize(window.innerWidth, window.innerHeight);

  camera.aspect = window.innerWidth / window.innerHeight;
  camera.updateProjectionMatrix();
}

window.addEventListener('resize', handleWindowResize);
```
I added an EventListener in order to listen for a window resize. Whenever this happened, the handleWindowResize() function would be called and update both the renderer's and camera's aspect ratio as well as the camera's projection matrix.

### 3.3 Coding the galaxy:
Once I got everything up and running correctly, I got to the big part of the project: The actual galaxy. Through extensive testing I came up with my result. The next part explains how the code works. Firstly, let's take a look on how the whole galaxy function looks and then, I'll go step by step explaining each part of this code:
```
let armCount = 6;
let armLength = 100;
const armSpread = 10;
const armRotationSpeed = 0.001;
const starCountPerArm = 1500;

const material = new THREE.PointsMaterial({
  size: 0.05,
  vertexColors: true,
});

const geometry = new THREE.BufferGeometry();
let positions = new Float32Array(armCount * starCountPerArm * 3);
let colors = new Float32Array(armCount * starCountPerArm * 3);

for (let armIndex = 0; armIndex < armCount; armIndex++) {
  const baseAngle = (armIndex / armCount) * Math.PI * 2;

  for (let i = 0; i < starCountPerArm; i++) {
    const angle = baseAngle + (i / starCountPerArm) * Math.PI * 2;
    const radius = (i / starCountPerArm) * armLength;
    const spread = Math.random() * armSpread;

    const x = Math.cos(angle) * radius + Math.random() * spread - spread / 2;
    const y = Math.random() * 4; // Small random displacement in the y-axis
    const z = Math.sin(angle) * radius + Math.random() * spread - spread / 2;

    const distanceFromCenter = Math.sqrt(x ** 2 + y ** 2 + z ** 2);
    const t = distanceFromCenter / armLength; // Value from 0 to 1 based on distance from the center

    const baseColor = new THREE.Color('rgb(255, 200, 100)');
    const centerColor = new THREE.Color('rgb(100, 150, 255)');

    const color = new THREE.Color().lerpColors(baseColor, centerColor, t);

    const index = (armIndex * starCountPerArm + i) * 3;

    positions[index] = x;
    positions[index + 1] = y;
    positions[index + 2] = z;

    colors[index] = color.r;
    colors[index + 1] = color.g;
    colors[index + 2] = color.b;
  }
}

geometry.setAttribute('position', new THREE.BufferAttribute(positions, 3));
geometry.setAttribute('color', new THREE.BufferAttribute(colors, 3));

const galaxy = new THREE.Points(geometry, material);
scene.add(galaxy);
```
### 3.3.1 Setting up the parameters:
Firstly, I had to declare the paramaters for my galaxy:
```
let armCount = 6;
let armLength = 100;
const armSpread = 10;
const armRotationSpeed = 0.001;
const starCountPerArm = 1500;
```

I declared the armCount and armLength as ``` let ``` variables as I wanted them to be customizable and thus, variable. Then, I declared the armSpread, armRotationSpeed and starCountPerArm as `const` as I wanted these to be fix values.

Then, I created the material for it:
```
const material = new THREE.PointsMaterial({
  size: 0.05,
  vertexColors: true,
});

const geometry = new THREE.BufferGeometry();
```
As I wanted it to be made of stars (points) I realized I had to work with particles. That's why I created a `THREE.PointsMaterial`. Since I wanted to create a custom geometry and not a predefined one, declared a `THREE.BufferGeometry`. Then, I declared 2 Float32Array objects:
```
let positions = new Float32Array(armCount * starCountPerArm * 3);
let colors = new Float32Array(armCount * starCountPerArm * 3);
```
The size of the coordinates and color values arrays is calculated based on the values of armCount and starCountPerArm variables. The size is determined by multiplying these two variables by 3, indicating that each element in the array represents a three-dimensional coordinate or a color value (x, y, z or r, g, b).

The purpose of these arrays is to store the positions and colors of the stars in the generated galaxy. Each star's position and color are calculated and stored in the respective array elements.


### 3.3.2 Calculating star coordinates and color values:

```
for (let armIndex = 0; armIndex < armCount; armIndex++) {
  const baseAngle = (armIndex / armCount) * Math.PI * 2;

  for (let i = 0; i < starCountPerArm; i++) {
    const angle = baseAngle + (i / starCountPerArm) * Math.PI * 2;
    const radius = (i / starCountPerArm) * armLength;
    const spread = Math.random() * armSpread;

    const x = Math.cos(angle) * radius + Math.random() * spread - spread / 2;
    const y = Math.random() * 4; // Small random displacement in the y-axis
    const z = Math.sin(angle) * radius + Math.random() * spread - spread / 2;

    const distanceFromCenter = Math.sqrt(x ** 2 + y ** 2 + z ** 2);
    const t = distanceFromCenter / armLength; // Value from 0 to 1 based on distance from the center

    const baseColor = new THREE.Color('rgb(255, 200, 100)');
    const centerColor = new THREE.Color('rgb(100, 150, 255)');

    const color = new THREE.Color().lerpColors(baseColor, centerColor, t);

    const index = (armIndex * starCountPerArm + i) * 3;

    positions[index] = x;
    positions[index + 1] = y;
    positions[index + 2] = z;

    colors[index] = color.r;
    colors[index + 1] = color.g;
    colors[index + 2] = color.b;
  }
}
```
Let's break down how this code works into 11 steps:
1. The outer loop iterates armIndex from 0 to armCount - 1. This loop controls the number of arms in the galaxy.

2. Inside the outer loop, the baseAngle is calculated based on the current armIndex. It determines the starting angle of each arm in radians.

3. The inner loop iterates i from 0 to starCountPerArm - 1. This loop controls the number of stars in each arm.

4. Inside the inner loop, the following calculations are performed to determine the position of each star:

    - `angle` is calculated by adding the baseAngle with the normalized value of `i` within the range of `starCountPerArm`. It determines the angle of the star around the arm.
    - `radius` is calculated by multiplying the normalized value of `i` within the range of `starCountPerArm` with the `armLength`. It determines the distance of the star from the center of the arm.
    - `spread` is a random value multiplied by `armSpread`. It adds some randomness to the star's position within the arm.
    - `x`, `y`, and `z` coordinates are calculated based on the `angle`, `radius`, and `spread` values using trigonometric functions. This determines the 3D position of each star.
    - `distanceFromCenter` is calculated as the Euclidean distance from the center (0, 0, 0) to the star's position.
    - `t` is calculated by dividing `distanceFromCenter` by `armLength`. It represents a value from 0 to 1 based on the distance of the star from the center.
5. The `baseColor` and `centerColor` are defined as `THREE.Color` objects representing the base center color (orange) and the center far color (blue) respectively.

6. The `color` of the star is calculated by interpolating between the `baseColor` and `centerColor` based on the t value. This creates a gradient effect along the arms.

7. An `index` is calculated based on the current `armIndex`, `starCountPerArm`, and `i`. It determines the position in the positions and colors arrays where the star's position and color will be stored.

8. The `x`, `y`, and `z` coordinates of the star's position are stored in the positions array at the calculated index.

9. The `r`, `g`, and `b` components of the star's color are stored in the colors array at the calculated index.

10. The inner loop continues to generate positions and colors for all stars in the current arm.

11. After both loops are complete, the coordinates and color values arrays will contain the coordinates and color values of all the stars in the galaxy.

After the calculation and storage of the `xyz` coordinates and `rgb` values, I declared 2 new `BufferAttributes` for the geometry:
```
geometry.setAttribute('position', new THREE.BufferAttribute(positions, 3));
geometry.setAttribute('color', new THREE.BufferAttribute(colors, 3));
```
### 3.3.3 Rendering and animating the galaxy:
And with that, I could create a `THREE.Points()` object to render my galaxy and add it to my scene:
```
const galaxy = new THREE.Points(geometry, material);
scene.add(galaxy);
```

I then added one more piece of code to the `animate()` function in order to animate the rotation of the galaxy:
```
function animate() {
  requestAnimationFrame(animate);

  galaxy.rotation.y += armRotationSpeed;

  composer.render();

}
```
### 3.4 Adding a Bloom Effect
```
import { RenderPass } from 'three/examples/jsm/postprocessing/RenderPass';
import { UnrealBloomPass } from 'three/examples/jsm/postprocessing/UnrealBloomPass';
import { EffectComposer } from 'three/examples/jsm/postprocessing/EffectComposer';
```
These three packages would let me add bloom to my object doing the following:
```
const bloomPass = new UnrealBloomPass(new THREE.Vector2(window.innerWidth, window.innerHeight), 1.5, 0.4, 0.85);
bloomPass.threshold = 0.4; // Adjust the threshold to control which pixels glow
bloomPass.strength = 1.7; // Adjust the strength of the glow effect
bloomPass.radius = 0.8; // Adjust the size of the glow effect

const composer = new EffectComposer(renderer);
composer.addPass(renderPass);
composer.addPass(bloomPass);
```
This is how this piece of code works:

1. `bloomPass` is created as an instance of `UnrealBloomPass`. It takes several parameters:

    - new `THREE.Vector2(window.innerWidth, window.innerHeight)`: This defines the size of the render target for the bloom effect, based on the current window size.
    - `1.5`: This is the strength of the bloom effect.
    - `0.4`: This is the threshold value that determines which pixels will be considered for the bloom effect. Pixels with a brightness above this threshold will be affected.
    - `0.85`: This is the blur radius of the bloom effect. It determines how far the bloom effect spreads.

2. The code then adjusts the settings of the bloomPass object:

    - `bloomPass.threshold = 0.4;`: This line sets the threshold value for the bloom effect to 0.4. You could adjust this value to control which pixels will glow based on their brightness.
    - `bloomPass.strength = 1.7;`: This line sets the strength of the bloom effect to 1.7. You could adjust this value to control the intensity of the glow effect.
    - `bloomPass.radius = 0.8;`: This line sets the radius of the bloom effect to 0.8. You could adjust this value to control the size of the glow effect.
3. An `EffectComposer` object named `composer` is created, which is responsible for managing and applying post-processing effects.
The `renderPass` and `bloomPass` are added to the composer using the `addPass` method. The `renderPass` represents the initial render of the scene, and the `bloomPass` applies the bloom effect to the rendered result.
### 3.5 Adding a GUI for customization:
In order for the galaxy to be customizable in the 4 parameters I was thinking, I would first have to add a way for the user to interact with the app. For that, I imported google's dat.gui:
```
import * as dat from 'dat.gui';
```
To create the GUI I simply needed to declare it:
```
const gui = new dat.GUI();
```
And then I needed to declare the parameters I wanted to customize:
```
const params = {
  galaxySize: 100,
  armCount: 6,
  baseColor: '#6496FF',
  centerColor: '#FFC864'
};
```
A nice GUI appeared on the top right corner of the screen! I created a div in my html in order to contain the GUI and I did the following to my CSS stylesheet in order for it to appear in the top right corner of the window:
```
<div id="gui-container"></div>
```
```
#gui-container {
  position: absolute;
  z-index: 1;
  top:10px;
  right: 10px;
}
```
I appended the GUI to the gui-container div element and called the `listen()` function after all the controls were loaded.
```
const guiContainer = document.getElementById('gui-container');
guiContainer.appendChild(gui.domElement);

gui.listen();
```

I created a function to update both the galaxy and the GUI display. In order to add actual mouse interactivity I had to the following:
```
gui.add(params, 'galaxySize', 10, 200).onChange(updateGalaxy);
gui.add(params, 'armCount', 1, 12).step(1).onChange(updateGalaxy);
gui.addColor(params, 'baseColor').onChange(updateGalaxy);
gui.addColor(params, 'centerColor').onChange(updateGalaxy);
```
Any time any of these parameters where changed the `updateGalaxy()` function would be called.

### 3.6 Update Galaxy function:
Let's take a look on how the updating the GUI code looks:
(Complete code snippet for reference)
```
function updateGalaxy() {
  armCount = params.armCount;
  armLength = params.galaxySize;

  baseColor.set(params.baseColor); // Update the base color
  centerColor.set(params.centerColor); // Update the center color

  generateGalaxy();

  gui.__controllers.forEach((controller) => {
    controller.updateDisplay();
  });
}
```
Let's look at this first:
```
    ...
  gui.__controllers.forEach((controller) => {
    controller.updateDisplay();
    ...
```
This code iterates over all the controllers in the GUI and calls the updateDisplay() method on each controller in order to change the display as it's interacted with.

Now let's look at the first part:
```
function updateGalaxy() {
  armCount = params.armCount;
  armLength = params.galaxySize;

  baseColor.set(params.baseColor); // Update the base color
  centerColor.set(params.centerColor); // Update the center color

  generateGalaxy();
```
See that `generateGalaxy()` function? Yes, the way I thought of updating every parameter in the galaxy was to generate a new galaxy!
### 3.7 Generating a new galaxy with the custom parameters:
```
function generateGalaxy() {

  galaxy.geometry.dispose();
  galaxy.material.dispose();
  scene.remove(galaxy);


  const newGeometry = new THREE.BufferGeometry();
  const newPositions = new Float32Array(armCount * starCountPerArm * 3);
  const newColors = new Float32Array(armCount * starCountPerArm * 3);

  for (let armIndex = 0; armIndex < armCount; armIndex++) {
    const baseAngle = (armIndex / armCount) * Math.PI * 2;

    for (let i = 0; i < starCountPerArm; i++) {
      const angle = baseAngle + (i / starCountPerArm) * Math.PI * 2;
      const radius = (i / starCountPerArm) * armLength;
      const spread = Math.random() * armSpread;

      const x = Math.cos(angle) * radius + Math.random() * spread - spread / 2;
      const y = Math.random() * 4; // Small random displacement in the y-axis
      const z = Math.sin(angle) * radius + Math.random() * spread - spread / 2;

      const distanceFromCenter = Math.sqrt(x ** 2 + y ** 2 + z ** 2);
      const t = distanceFromCenter / armLength;

      const baseColor = new THREE.Color(params.baseColor);
      const centerColor = new THREE.Color(params.centerColor);

      const color = new THREE.Color().lerpColors(centerColor, baseColor, t);

      const index = (armIndex * starCountPerArm + i) * 3;

      newPositions[index] = x;
      newPositions[index + 1] = y;
      newPositions[index + 2] = z;

      newColors[index] = color.r;
      newColors[index + 1] = color.g;
      newColors[index + 2] = color.b;
    }
  }

  newGeometry.setAttribute('position', new THREE.BufferAttribute(newPositions, 3));
  newGeometry.setAttribute('color', new THREE.BufferAttribute(newColors, 3));

  galaxy.geometry = newGeometry;
  galaxy.material = material;
  scene.add(galaxy);
}
```

1. It first removes the old galaxy so a new one doesn't render on top, causing obvious visual issues.
```
  galaxy.geometry.dispose();
  galaxy.material.dispose();
  scene.remove(galaxy);
```
2. Then it declares a new `THREE.BufferGeometry()` and 2 new `Float32Array` objects.
```
  const newGeometry = new THREE.BufferGeometry();
  const newPositions = new Float32Array(armCount * starCountPerArm * 3);
  const newColors = new Float32Array(armCount * starCountPerArm * 3);
```
3. After that, a new nested loop calculates every coordinate and rgb value (rgb values according to the parameters). This loop is pretty much similar to the one that created the original galaxy.

4. Setting 2 new BufferAttributes:
```
  newGeometry.setAttribute('position', new THREE.BufferAttribute(newPositions, 3));
  newGeometry.setAttribute('color', new THREE.BufferAttribute(newColors, 3));
```
5. Adding the new galaxy to the scene:
```
  galaxy.geometry = newGeometry;
  galaxy.material = material;
  scene.add(galaxy);
```
### 3.8 Animating the scene:
That's almost it for the code! Afterall I already had a nice functional auto-rotating customizable galaxy. All I had to add was a camera animation and animated HTML elements to make it prettier.

For that I imported the GSAP library:
```
import gsap from 'gsap';
```
### 3.8.1 Animating the camera on click:
```
let cameraAnimationCompleted = false;

function animateCamera() {
  gsap.to(camera.position, {
    x: 0,
    y: 70,
    z: 200,
    duration: 4,
    onComplete: () => {
      cameraAnimationCompleted = true;
    }
  });
}

function handleClick() {
  if (!cameraAnimationCompleted) {
    animateCamera();
  }
}

window.addEventListener('click', handleClick,{ once: true });
```

I added this function to move the camera from a far away position from the galaxy to a close one. I updated the original position of the galaxy to:
```
camera.position.set(300, 3000, 5000);
```
I only wanted this animation to be executed once onclick so I declared a variable and set it to false:
```
let cameraAnimationCompleted = false;
```
Once the function was called and completed, the variable was set to true. To handle the click, I created:
```
function handleClick() {
  if (!cameraAnimationCompleted) {
    animateCamera();
  }
}
```
This checks if the function has been completed so it never executes again.

The eventListener is set to `{ once: true }` so once it fires it never fires again. I did this because it was overriding the GUI controls.
### 3.8.2 Adding HTML elements, animating them and fading them out on click:
For the HTML elements, I wrote the following in the html file:
```
<div class="container" id="text">
        <div class="content">
            <h1>CS50<br>Final Project</h1>
            <p>A customizable galaxy implemented through JS, Three.js, HTML and CSS.<br><br><b>Click to continue.</b></p>
        </div>
        <div class="clicker">
            <p>Click to continue.</p>
        </div>
    </div>
    <div id="gui-container"></div>
    <canvas class="webgl"></canvas>
    <script src="https://cdnjs.cloudflare.com/ajax/libs/gsap/3.11.5/gsap.min.js" integrity="sha512-cOH8ndwGgPo+K7pTvMrqYbmI8u8k6Sho3js0gOqVWTmQMlLIi6TbqGWRTpf1ga8ci9H3iPsvDLr4X7xwhC/+DQ==" crossorigin="anonymous" referrerpolicy="no-referrer"></script>
    <script src="https://cdnjs.cloudflare.com/ajax/libs/gsap/3.11.5/CSSRulePlugin.min.js" integrity="sha512-zaTjCyJwbhpd8V594wpmUStv6Dy/SnmP7jR+XXnE49z2ayHkSirlNiP4XQc15Zgk+p5gXGe5ZUQYu4yRtShqkQ==" crossorigin="anonymous" referrerpolicy="no-referrer"></script>
```
It's a nice text that serves as an initial presentation an view to the app. I imported the GSAP library and CSSRulePlugin to create a nice "appearing from nowhere animation". That was achieved with the following JavaScript code.

```
    const content = CSSRulePlugin.getRule('.content:before')
    const h1 = document.querySelector('h1')
    const p = document.querySelector('p')
    const tl = gsap.timeline()

    tl.from(content, { delay: .5, duration: 4, cssRule: {scaleX: 0}})
    tl.to(h1, { duration: 2, clipPath: 'polygon(0 0, 100% 0, 100% 100%, 0% 100%)', y:'30px'}, "-=3")
    tl.to(p, { duration: 4, clipPath: 'polygon(0 0, 100% 0, 100% 100%, 0% 100%)', y:'30px'}, "-=2")

    window.addEventListener('click', function() {
        var myDiv = document.getElementById('text');
        myDiv.classList.add('fade-out');
    }, { once: true });
```
Let's look at the CSS for this too:
```
.container {
  position: absolute;
  z-index: 1;
  width: 100%;
  height: 100vh;
  display: grid;
  place-content: center;
}

.content {
  display: flex;
  gap: 5em;
  width: 100%;
  padding-top: 3em;
  position: relative;
}

.content:before {
  content: '';
  position: absolute;
  top: 0;
  left: 0;
  width: 100%;
  border-bottom: 1px solid white;
  transform: scaleX(1);
}

h1 {
  font-size: 4rem;
  width: 50vw;
  line-height: 97%;
  text-align: right;
  font-weight: 400;
}

h1, p {
  flex-basis: 0;
  flex-grow: 1;
  clip-path: polygon(0 0, 100% 0, 100% 0, 0 0);
}

p {
  font-size: 1.3rem;
  width: 40vw;
  font-weight: 200;
}
```
A line is set to appear once the page loads. This achieved by hiding it with:
```
    tl.from(content, { delay: .5, duration: 4, cssRule: {scaleX: 0}})
```
This line of code tells it to go from a scale of 0 in the X plane to its original scale set in the CSS:
```
.content:before {
  content: '';
  position: absolute;
  top: 0;
  left: 0;
  width: 100%;
  border-bottom: 1px solid white;
  transform: scaleX(1);
}
```
The header and paragraphs "appear from nowhere" thanks to the use of GSAP. It animates a clip path downwards, revealing the hidden text.
```
tl.to(h1, { duration: 2, clipPath: 'polygon(0 0, 100% 0, 100% 100%, 0% 100%)', y:'30px'}, "-=3")
tl.to(p, { duration: 4, clipPath: 'polygon(0 0, 100% 0, 100% 100%, 0% 100%)', y:'30px'}, "-=2")
```
The `polygon` is the shape of the clipping mask.
After all the text appears, it prompts you to click in order to continue. This creates a fade-out animation and the consequencial zooming of the camera. The fade out is achieved with JavaScript and CSS:
JavaScript:
```
    window.addEventListener('click', function() {
        var myDiv = document.getElementById('text');
        myDiv.classList.add('fade-out');
    }, { once: true });
```
Added CSS class:
```
.fade-out {
  opacity: 0;
  transition: opacity 0.5s;
}
```

## 4. This was my CS50 Final Project!
This has been a journey which I hope to continue for the years to come. Thank you, CS50, for imparting us with invaluable coding knowledge and the endless opportunities that stem from adopting a programming mindset!

I would like to extend my sincerest regards to the entire CS50 staff, with a special expression of gratitude to Professor David J. Malan for his exceptional lectures.

Thank you for reading this document.

Alex Álvarez de Sotomayor Sugimoto,\
CS50 Student