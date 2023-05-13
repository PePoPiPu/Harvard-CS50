import './styles.css';
import * as THREE from 'three';
import { OrbitControls } from 'three/examples/jsm/controls/OrbitControls';
import { EffectComposer } from 'three/examples/jsm/postprocessing/EffectComposer';
import { RenderPass } from 'three/examples/jsm/postprocessing/RenderPass';
import { UnrealBloomPass } from 'three/examples/jsm/postprocessing/UnrealBloomPass';

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

// Controls
const controls = new OrbitControls(camera, renderer.domElement);

// Galaxy Parameters
const armCount = 6; // Number of arms in the galaxy
const armLength = 100; // Length of each arm
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
const positions = new Float32Array(armCount * starCountPerArm * 3);
const colors = new Float32Array(armCount * starCountPerArm * 3);

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

    const hotColor = new THREE.Color('rgb(255, 200, 100)'); // Hot center color (orange)
    const coldColor = new THREE.Color('rgb(100, 150, 255)'); // Cold far color (blue)

    const color = new THREE.Color().lerpColors(hotColor, coldColor, t); // Gradient between hot and cold colors

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

// Create a bloom pass with desired parameters
const bloomPass = new UnrealBloomPass(new THREE.Vector2(window.innerWidth, window.innerHeight), 1.5, 0.4, 0.85);
bloomPass.threshold = 0.9; // Adjust the threshold to control which pixels glow
bloomPass.strength = 1.2; // Adjust the strength of the glow effect
bloomPass.radius = 0.5; // Adjust the size of the glow effect

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
