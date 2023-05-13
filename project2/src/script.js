import './styles.css';
import * as THREE from 'three';
import { OrbitControls } from 'three/examples/jsm/controls/OrbitControls';

// Canvas
const canvas = document.querySelector('canvas.webgl');

// Scene
const scene = new THREE.Scene();

// Camera
const camera = new THREE.PerspectiveCamera(75, window.innerWidth / window.innerHeight, 0.1, 1000);
camera.position.set(0, 10, 30);

// Renderer
const renderer = new THREE.WebGLRenderer({ canvas: canvas });
renderer.setSize(window.innerWidth, window.innerHeight);

// Controls
const controls = new OrbitControls(camera, renderer.domElement);

// Galaxy Parameters
const armCount = 6; // Number of arms in the galaxy
const armLength = 10; // Length of each arm
const armSpread = 10; // Spread of the arms
const armRotationSpeed = 0.001; // Rotation speed of the arms

// Material
const material = new THREE.PointsMaterial({
  size: 0.05, // Size of each star
  vertexColors: true, // Enable vertex colors
});

// Geometry
const geometry = new THREE.BufferGeometry();
const positions = new Float32Array(armCount * armLength * 3);
const colors = new Float32Array(armCount * armLength * 3);

// Generate the stars
for (let armIndex = 0; armIndex < armCount; armIndex++) {
  const baseAngle = (armIndex / armCount) * Math.PI * 2;

  for (let i = 0; i < armLength; i++) {
    const angle = baseAngle + i * 0.1;
    const radius = i / armLength * armSpread;

    const x = Math.cos(angle) * radius;
    const y = 0; // Keep the y value constant to make it flat
    const z = Math.sin(angle) * radius;

    const color = new THREE.Color().setHSL(angle / (Math.PI * 2), 1, 0.5); // Color based on angle

    const index = (armIndex * armLength + i) * 3;

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

