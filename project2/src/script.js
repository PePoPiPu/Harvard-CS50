import './styles.css';
import * as THREE from 'three';
import * as dat from 'dat.gui';
import { OrbitControls } from 'three/examples/jsm/controls/OrbitControls';
import { RenderPass } from 'three/examples/jsm/postprocessing/RenderPass';
import { UnrealBloomPass } from 'three/examples/jsm/postprocessing/UnrealBloomPass';
import { EffectComposer } from 'three/examples/jsm/postprocessing/EffectComposer';

// Canvas
const canvas = document.querySelector('canvas.webgl');

// Scene
const scene = new THREE.Scene();

// Camera
const camera = new THREE.PerspectiveCamera(75, window.innerWidth / window.innerHeight, 0.1, 10000);
camera.position.set(0, 70, 200);

// Renderer
const renderer = new THREE.WebGLRenderer({ canvas: canvas });
renderer.setSize(window.innerWidth, window.innerHeight);

// Function to handle window resize
function handleWindowResize() {
  // Update renderer size
  renderer.setSize(window.innerWidth, window.innerHeight);

  // Update camera aspect ratio
  camera.aspect = window.innerWidth / window.innerHeight;
  camera.updateProjectionMatrix();
}

// Controls
const controls = new OrbitControls(camera, renderer.domElement);

// Galaxy Parameters
let armCount = 6; // Number of arms in the galaxy
let armLength = 100; // Length of each arm
const armSpread = 10; // Spread of the arms
const armRotationSpeed = 0.001; // Rotation speed of the arms
const starCountPerArm = 1500; // Number of stars in each arm

// Material
const material = new THREE.PointsMaterial({
  size: 0.05, // Size of each star
  vertexColors: true, // Enable vertex colors
});

// Geometry
const geometry = new THREE.BufferGeometry();
let positions = new Float32Array(armCount * starCountPerArm * 3);
let colors = new Float32Array(armCount * starCountPerArm * 3);

// Generate the stars
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

    const baseColor = new THREE.Color('rgb(255, 200, 100)'); // base center color (orange)
    const centerColor = new THREE.Color('rgb(100, 150, 255)'); // center far color (blue)

    const color = new THREE.Color().lerpColors(baseColor, centerColor, t); // Gradient between base and center colors

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

// Points
const galaxy = new THREE.Points(geometry, material);
scene.add(galaxy);

// Create a render pass to render the scene
const renderPass = new RenderPass(scene, camera);

// Add event listener for window resize
window.addEventListener('resize', handleWindowResize);


// Create a bloom pass with desired parameters
const bloomPass = new UnrealBloomPass(new THREE.Vector2(window.innerWidth, window.innerHeight), 1.5, 0.4, 0.85);
bloomPass.threshold = 0.4; // Adjust the threshold to control which pixels glow
bloomPass.strength = 1.7; // Adjust the strength of the glow effect
bloomPass.radius = 0.8; // Adjust the size of the glow effect

// Create an effect composer
const composer = new EffectComposer(renderer);
composer.addPass(renderPass);
composer.addPass(bloomPass);

// Animation loop
function animate() {
  requestAnimationFrame(animate);

  // Rotate the arms
  galaxy.rotation.y += armRotationSpeed;

  // Render the scene through the composer
  composer.render();

  // Update controls
  controls.update();
}

// Start the animation loop
animate();


// Create a GUI object
const gui = new dat.GUI();


// Parameters
const params = {
  galaxySize: 100,
  armCount: 6,
  baseColor: '#ff6600',
  centerColor: '#ffaa00' // New parameter for the center color
};

// Add controls to the GUI
gui.add(params, 'galaxySize', 10, 200).onChange(updateGalaxy);
gui.add(params, 'armCount', 1, 12).step(1).onChange(updateGalaxy);
gui.addColor(params, 'baseColor').onChange(updateGalaxy);
gui.addColor(params, 'centerColor').onChange(updateGalaxy);

let baseColor = new THREE.Color(params.baseColor); // Initialize the base color
let centerColor = new THREE.Color(params.centerColor); // Initialize the center color

// Function to update the galaxy based on the GUI parameters
function updateGalaxy() {
  armCount = params.armCount;
  armLength = params.galaxySize;

  baseColor.set(params.baseColor); // Update the base color
  centerColor.set(params.centerColor); // Update the center color

  generateGalaxy();
}

// Function to generate the galaxy
function generateGalaxy() {
  // Clear existing galaxy
  galaxy.geometry.dispose();
  galaxy.material.dispose();
  scene.remove(galaxy);

  // Generate new galaxy
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
      const t = distanceFromCenter / armLength; // Value from 0 to 1 based on distance from the center

      const baseColor = new THREE.Color(params.baseColor); // Base color from the GUI
      const centerColor = new THREE.Color(params.centerColor); // Center color from the GUI

      const color = new THREE.Color().lerpColors(baseColor, centerColor, t); // Gradient between hot and cold colors

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

// Append GUI to the DOM
const guiContainer = document.getElementById('gui-container');
guiContainer.appendChild(gui.domElement);

gui.listen();