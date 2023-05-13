import './styles.css';
import * as THREE from 'three';
import { OrbitControls } from 'three/examples/jsm/controls/OrbitControls';

// Canvas
const canvas = document.querySelector('canvas.webgl');

// Scene
const scene = new THREE.Scene();

// Camera
const camera = new THREE.PerspectiveCamera(75, window.innerWidth / window.innerHeight, 0.1, 10000);
camera.position.z = 1500;

// Renderer
const renderer = new THREE.WebGLRenderer({ canvas: canvas });
renderer.setSize(window.innerWidth, window.innerHeight);

// Controls
const controls = new OrbitControls(camera, renderer.domElement);

// Galaxy Parameters
const galaxySize = 1000;
const numStars = 10000;
const armCount = 4;
const armRotationSpeed = 0.002;
const armLength = 0.5;
const armThickness = 0.2;

// Colors
const colorStart = new THREE.Color(0x8000ff); // Starting color
const colorEnd = new THREE.Color(0x00ff00); // Ending color

// Geometry
const geometry = new THREE.BufferGeometry();
const positions = new Float32Array(numStars * 3);
const colors = new Float32Array(numStars * 3);
const sizes = new Float32Array(numStars);

for (let i = 0; i < numStars; i++) {
  const t = i / numStars;
  const armAngle = (armCount * 2 * Math.PI * t) + (armRotationSpeed * t);
  const radius = Math.random() * galaxySize;

  const x = Math.cos(armAngle) * radius;
  const y = Math.sin(armAngle) * radius * armThickness;
  const z = (t - 0.5) * armLength;

  positions[i * 3] = x;
  positions[i * 3 + 1] = y;
  positions[i * 3 + 2] = z;

  const color = new THREE.Color().lerpColors(colorStart, colorEnd, t);
  colors[i * 3] = color.r;
  colors[i * 3 + 1] = color.g;
  colors[i * 3 + 2] = color.b;

  sizes[i] = 0.5;
}

geometry.setAttribute('position', new THREE.BufferAttribute(positions, 3));
geometry.setAttribute('color', new THREE.BufferAttribute(colors, 3));
geometry.setAttribute('size', new THREE.BufferAttribute(sizes, 1));

// Material
const material = new THREE.PointsMaterial({
  vertexColors: true,
  sizeAttenuation: true,
  size: 1,
  transparent: true,
  alphaTest: 0.5,
});

// Points
const galaxy = new THREE.Points(geometry, material);
scene.add(galaxy);

// Animation loop
function animate() {
  requestAnimationFrame(animate);

  // Rotate the arms
  galaxy.rotation.z += armRotationSpeed;

  // Render the scene
  renderer.render(scene, camera);
}

// Start the animation loop
animate();
