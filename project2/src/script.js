import './styles.css';
import * as THREE from 'three';
import { OrbitControls } from 'three/examples/jsm/controls/OrbitControls';

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
    const t = distanceFromCenter / (armCount * armLength); // Value from 0 to 1 along the arms

    const color = new THREE.Color().setHSL(0.1 + t * 0.9, 1, 0.5 - t * 0.8); // Orange to blue gradient

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

// Animation loop
function animate() {
  requestAnimationFrame(animate);

  // Rotate the arms
  galaxy.rotation.y += armRotationSpeed;

  // Render the scene
  renderer.render(scene, camera);
}

// Start the animation loop
animate();
